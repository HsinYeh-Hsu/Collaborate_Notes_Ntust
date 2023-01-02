# 專題筆記
12/27, 2022 ~ 01/02, 2023

### 進度
- 看 Django 相關的影片
- 學習更多 CSS，像是 grid、transform...
- 使用 VMware 架設 VM，與本機共享資料夾，並透過 VSCode SSH 進去操作
- 透過 ThreeJS 完成網頁全景功能
  - [程式碼](https://github.com/wei06097/ThreeJS)
  - [網站](https://wei06097.github.io/ThreeJs/)

### 參考資料
- [Django Web](https://youtu.be/onDgK-bTvjM)
- [transform 3D](https://eyesofkids.gitbooks.io/css3/content/contents/transform3d.html)
- [30 天 CSS 隨手筆記](https://ithelp.ithome.com.tw/users/20103812/ironman/1213)
- [VSCode Remote SSH](https://youtube.com/watch?v=w8KJHY3Rplc&feature=shares)
- [Linux 和 Windows 共享文件夹](https://blog.csdn.net/qq_43516928/article/details/119430588)
- [實現 360 全景的 N 種方案](https://developer.aliyun.com/article/783218)
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