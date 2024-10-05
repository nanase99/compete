FROM debian:trixie-slim
ARG USERNAME
ENV TZ=Asia/Tokyo

RUN useradd -m -d /home/$USERNAME -s /bin/bash $USERNAME && \
    apt update && \
    apt upgrade -y && \
    apt install -y procps && \
    apt install -y nodejs npm && \
    apt install -y tzdata g++ gdb && \
    npm install -y -g atcoder-cli && \
    apt install -y python3 && \
    apt install -y python3-pip && \
    pip3 install --break-system-packages online-judge-tools && \
    apt install -y expect && \
    echo 'alias accs="acc s -s -- -y"' >> /home/$USERNAME/.bashrc


COPY --chown=$USERNAME:$USERNAME ./acc/config/ /home/$USERNAME/.config/atcoder-cli-nodejs/