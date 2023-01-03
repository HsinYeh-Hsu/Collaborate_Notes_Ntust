# 專題筆記
12/27, 2022 ~ 01/02, 2023

### 進度
- 學了一點點 Django
- 學習更多 CSS，像是 grid、transform...
- 使用 VMware、共享資料夾、SSH
- 學習 Docker
- 透過 ThreeJS 完成網頁全景功能
  - [程式碼](https://github.com/wei06097/ThreeJS)
  - [網站](https://wei06097.github.io/ThreeJs/)

### 參考資料
- [Django Web](https://youtu.be/onDgK-bTvjM)
- [transform 3D](https://eyesofkids.gitbooks.io/css3/content/contents/transform3d.html)
- [30 天 CSS 隨手筆記](https://ithelp.ithome.com.tw/users/20103812/ironman/1213)
- [CSS Grid Layout 格線佈局教學](https://youtu.be/lI81W0A-GUc)
- [VSCode Remote SSH](https://youtube.com/watch?v=w8KJHY3Rplc&feature=shares)
- [Linux 和 Windows 共享文件夹](https://blog.csdn.net/qq_43516928/article/details/119430588)
- [Docker - 介紹及安裝教學](https://blog.kennycoder.io/2020/01/12/Docker-%E4%BB%8B%E7%B4%B9%E5%8F%8A%E5%AE%89%E8%A3%9D%E6%95%99%E5%AD%B8/)
- [Docker Container](https://azole.medium.com/docker-container-%E5%9F%BA%E7%A4%8E%E5%85%A5%E9%96%80%E7%AF%87-1-3cb8876f2b14)
- [Container Networking](https://docs.docker.com/config/containers/container-networking/)
- [一定要學的 Docker 10大指令](https://www.youtube.com/watch?v=sxuynZ3wIa8)
- [實現 360 全景的 N 種方案](https://developer.aliyun.com/article/783218)
- [Three.js 瀏覽器中的 3D 渲染引擎](https://youtu.be/E4rxBWm4nhA)
- [SphereGeometry](https://threejs.org/docs/#api/en/geometries/SphereGeometry)

---

VS Code 連到 Ubuntu 
---
### Ubuntu
- 安裝
`sudo apt update`
`sudo apt install openssh-server`
- 查看狀態
`service ssh status`
`ip address`

### VS Code
- ssh 連接
`ssh name@ip` ex: `ssh dev@192.168.175.128`

### 共享資料夾
- 安裝 vmtools
`sudo apt install open-vm-tools`
- 查看共享目錄
`vmware-hgfsclient`
- 查看共享檔案
`sudo mkdir /mnt/hgfs`
`sudo vmhgfs-fuse .host:/ /mnt/hgfs`
`sudo su`
`chmod -R 777 /mnt`

![](https://i.imgur.com/W2aJMu4.png)

安裝環境
---
- 已安裝
`apt list --installed`
- 解除安裝
`sudo apt remove 套件`
- Python
`sudo apt install python-pip`

Docker
---
### 安裝
1. 系統更新
`sudo apt update` `sudo apt upgrade` `sudo apt autoremove`
2. 安裝 docker
`sudo apt-get install docker.io`
3. 檢查 docker 服務有無正常啟動
`service docker status`
4. 將自己使用者帳號加入 docker 群組
`sudo usermod -aG docker 使用者名稱`
5. 檢查
`docker version` `docker --version`
6. 測試
`docker run hello-world`
### 組成
- Dockerfile
腳本
- Image
這是一個唯讀的模板，可用來建立 container。如果有學過物件導向語言，可以想成 image 就是 class、container 是 object 或是 instance。
- Container
這就是我們的主角，是一個獨立、隔離的空間，裡面包括了我們執行一個應用程式所需要的元件。
- Docker registry
這其實就很像 github，裡面存放了很多 images，公開的像是 Docker Hub，你也可以建立自己私人的 registry。

![](https://miro.medium.com/max/750/1*DkIQGsv9YsPgB0dQpIfikA.webp)

### 使用

- 指令
    - `-a` 全部
    - `-d` 背景
    - `-i` attach 時鍵盤輸入會被 Container 接手。
    - `-t` attach 時 Container 的螢幕會接到原來的螢幕上。
    - `-p` port mapping
    
    | Flag value | Description |
    | -------- | -------- |
    | `-p 8080:80` | Map TCP port 80 in the container to port 8080 on the Docker host |
    | `-p 192.168.175.128:8080:80` | Map TCP port 80 in the container to port 8080 on the Docker host for connections to host IP 192.168.175.128 |
    | `-p 8080:80/udp` | Map UDP port 80 in the container to port 8080 on the Docker host |
    
- Image
    - `docker images` 
    - `docker run <image name>`
    - `docker rmi <image name>`

- Container
    - `docker container ls -a`
    - `docker container stop <container id>`
    - `docker container rm <container id>`

- Docker Hub
    - `docker logout`
    - `docker login`
    - `docker build -t <account name>/<image name> .`
    - `docker push <image name>`

- 開啟 Container 流程
    - 建立 image
    `docker build -t <image name> <dockerfile location>`
    - 建立 container
    `docker run -d -p 192.168.175.128:80:80 <image name>`
    
### 結果
![](https://i.imgur.com/O1CuHzR.png)