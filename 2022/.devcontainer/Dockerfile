FROM gcc:12.2.0
ARG USER=developer
ARG UID=1000

USER 0

RUN set -eux; \
  apt-get update --yes; \
  apt-get install --yes --no-install-recommends \
    clang-format \
    clang-tidy \
    iwyu \
    pip \
    gdb \
    sudo \
    wget; \
  rm -rf /var/lib/apt/lists/*;

# Install CMake
RUN set -eux; \
  CMAKE_VERSION=3.25.1; \
  wget \
    --progress=dot:mega \
    --output-document=cmake.sh \
    https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-Linux-x86_64.sh; \
  chmod 744 cmake.sh; \
  mkdir /opt/cmake; \
  ./cmake.sh --prefix=/opt/cmake --skip-license --exclude-subdir; \
  ln -s /opt/cmake/bin/ccmake /usr/bin/ccmake; \
  ln -s /opt/cmake/bin/ctest /usr/bin/ctest; \
  ln -s /opt/cmake/bin/cpack /usr/bin/cpack; \
  ln -s /opt/cmake/bin/cmake /usr/bin/cmake; \
  rm cmake.sh;
  
# Install tools available in PyPI
RUN set -eux; \
  pip install --no-cache-dir \
    cmakelang[YAML]==0.6.13 \
    lizard==1.17.10;

# Install hadolint (dockerfile linter)
RUN set -eux; \
  HADOLINT_VERSION=2.10.0; \
  wget \
    --progress=dot:giga \
    --output-document=/usr/bin/hadolint \
    https://github.com/hadolint/hadolint/releases/download/v${HADOLINT_VERSION}/hadolint-Linux-x86_64; \
  chmod +x /usr/bin/hadolint;

# Install shellcheck
RUN set -eux; \
  SHELLCHECK_VERSION=0.8.0; \
  wget \
    --progress=dot:giga \
    https://github.com/koalaman/shellcheck/releases/download/v0.8.0/shellcheck-v${SHELLCHECK_VERSION}.linux.x86_64.tar.xz; \
  tar -xJf shellcheck-v${SHELLCHECK_VERSION}.linux.x86_64.tar.xz; \
  cp shellcheck-v${SHELLCHECK_VERSION}/shellcheck /usr/local/bin; \
  rm -rf shellcheck-v${SHELLCHECK_VERSION}.linux.x86_64.tar.xz shellcheck-v${SHELLCHECK_VERSION};
  
# Build cppcheck
RUN set -eux; \
  CPPCHECK_VERSION=2.8.1; \
  git clone --depth 1 --branch ${CPPCHECK_VERSION} https://github.com/danmar/cppcheck.git; \
  cmake -B build \
    -D BUILD_TESTING=off \
    -D USE_MATCHCOMPILER=on \
    -D CMAKE_BUILD_TYPE=Release \
    cppcheck; \
  cmake --build build --target install; \
  rm -r build cppcheck;

# Add developer user
RUN set -eux; \
  groupadd --gid $UID $USER; \
  adduser --shell /bin/bash --uid $UID --gid $UID --gecos "" --disabled-password $USER; \
  echo "$USER ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers;

# Switch to our non-root user
USER ${UID}

ENTRYPOINT ["/bin/bash"]