FROM emscripten/emsdk:3.1.7

RUN \
  apt update -y && \
  apt install -y \
    bash \
    build-essential \
    cmake \
    curl \
    git \
    libffi-dev \
    libgdbm-dev \
    libncurses5-dev \
    libnss3-dev \
    libreadline-dev \
    libsqlite3-dev \
    libssl-dev \
    libbz2-dev \
    npm \
    python3 \
    python3-pip \
    python3-setuptools \
    zlib1g-dev

RUN \
  pip install \
    libclang \
    pyyaml \
    cerberus \
    argparse

WORKDIR /rapidjson/
RUN \
  git clone https://github.com/Tencent/rapidjson.git .

WORKDIR /freetype/
RUN \
  git clone https://git.savannah.nongnu.org/git/freetype/freetype2.git .

ENV OCCT_COMMIT_HASH_FULL d2abb6d844231cb8f29be6894440874a4700e4a5
WORKDIR /occt/
RUN \
  curl "https://git.dev.opencascade.org/gitweb/?p=occt.git;a=snapshot;h=${OCCT_COMMIT_HASH_FULL};sf=tgz" -o occt.tar.gz && \
  tar -xvf occt.tar.gz && \
  export OCCT_COMMIT_HASH=$(echo ${OCCT_COMMIT_HASH_FULL} | cut -c 1-7) && \
  mv occt-$OCCT_COMMIT_HASH/* . && \
  mv occt-$OCCT_COMMIT_HASH/.* . || true && \
  rm occt-$OCCT_COMMIT_HASH -r

WORKDIR /opencascade.js/
COPY src ./src

ARG threading=single-threaded

RUN \
  mkdir /opencascade.js/build/ && \
  mkdir /opencascade.js/dist/ && \
  /opencascade.js/src/applyPatches.py && \
  /opencascade.js/src/generateBindings.py && \
  /opencascade.js/src/compileBindings.py ${threading} && \
  /opencascade.js/src/compileSources.py ${threading} && \
  chmod -R 777 /opencascade.js/ && \
  chmod -R 777 /occt

COPY builds ./builds

WORKDIR /src/

ENV threading=$threading

ENTRYPOINT ["/opencascade.js/src/buildFromYaml.py"]
