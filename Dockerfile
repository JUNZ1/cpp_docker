FROM ubuntu
RUN apt-get update
RUN apt-get install git -y
RUN apt-get install cmake -y
RUN apt-get install build-essential -y
RUN apt-get install gdb -y
WORKDIR /home/workspace/
COPY . .
