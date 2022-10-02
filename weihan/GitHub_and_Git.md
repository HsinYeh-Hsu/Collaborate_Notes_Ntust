# 專題筆記: GitHub 與 Git
09/22 - 09/28, 2022
09/29 - 10/05, 2022

<!-- -------------------------------------------------- -->
GitHub & Git
---

GitHub 是線上軟體原始碼代管服務平台，使用Git作為版本控制軟體
Git 是一款分散式的版控系統，每個開發者都有一份完整的本機儲存庫

除了在遠端儲存庫上，擁有專案各版本的完整程式碼之外，在每一個開發者本機端也還設計了一個本地端儲存庫（Repository），也儲存了所有變更過的檔案，以及專案各版本的歷史紀錄。遠端儲存庫並非是唯一一份，而是一個供多人同步專案資料用的共享版本。

- 分散式優點: 網路依賴低
- 分散式缺點: 權限控管稍微麻煩

### 架構

![使用 Git 備份資料到 GitHub](https://i.imgur.com/CzQLvDv.png)

- working directory（工作目錄）：

    工作目錄主要是存放需要控制版本的檔案資料夾。經由在資料夾內建立 git 的資料庫，此資料夾就能變成 git 的工作目錄。
    
- staging area（準備提交區）

    準備提交區用於紀錄將要被提交的資料。若在工作目錄下的檔案有變動，且我們希望能提交這些更新過的資料，就將這些資料存入準備提交區，此狀態下只標記要被提交的資料，尚未將資料提交出去。

- local repository（本地資料庫）

    即為自己電腦端上的資料庫。當確定好所有要提交的資料都加入到準備提交區之後，可以將準備提交區的資料做提交紀錄，提交後的資料會被紀錄成一個提交紀錄保存於資料庫中。

- remote repository（遠端資料庫）

    即為遠端伺服器上的資料庫。當本地資料備齊後，我們可以透過上傳將資料保存到遠端資料庫，也可以反過來將遠端資料庫的紀錄同步下來。

<!-- -------------------------------------------------- -->
Git 指令
---

### 基本指令

    - git init
    建立本地資料庫
    
    - git status
    查看資料夾內的檔案狀態: 是否修改、新增
    
    - git log
    查看資料庫紀錄
    
    - gitk
    啟動圖形介面
    
    - git checkout <ID>
    移動到指定的提交紀錄
    
### 本地資料操作

    - git add <file name>
    將檔案加入到準備提交區
    
    - git add .
    將所有檔案加入到準備提交區
    
    - git commit -m "<remark>"
    把準備提交區的檔案儲存到資料庫中
    
    - git reset --soft head~<n>
    回到前n次commit的狀態
    
    - git reset -- <file name>
    將檔案從準備提交區移除
    
    - git checkout -- <file name>
    將檔案重置到上次commit的狀態
    
### 遠端+本地資料操作
    
    - git remote add origin <DB URL>
    連結遠端資料庫
    
    - git push origin <branch name>
    將資料同步至遠端 (origin 前加上 -u 設定預設)
    
    - git pull origin <branch name>
    同步資料庫到工作目錄 (下載、合併分支、解決conflict)
    
    - git clone <DB Link>
    將遠端的資料庫複製到本地端 (下載完整專案)
    
    - git clone -b <branch name> <DB URL>
    不下載主線程式碼，只下載支線程式碼
    
### Branch
    
    - git branch
    查看所有分支
    
    - git branch -a
    查看所有分支 (包含 remote)
    
    - git checkout -b <branch name>
    建立新分支
    
    - git branch -d <branch name>
    刪除分支
    
    - git switch <branch name>
    切換分支 (要把全部檔案commit後才能切換)
    
    - git branch -m <new branch name>
    重新命名目前的分支名稱
    
    - git push -u origin <branch name>
    將branch推到GitHub

### Merge

- 要養成一個習慣，每次push前，先切到本地master把origin拉下來，再去本地分支做rebase，解conflict後再推出去

方法1: GitHub進行merge
    
    在 master 分支進行 git pull
    回到 new-feature 進行 git rebase master
    解決 conflict 後存檔進行 git add
    git rebase --continue (可能要重複好幾次)
    
    git log 確認
    git push -f 強制 push (會改變歷史紀錄，共協的分支不要使用)
    刪掉不要的分支
    回到 GitHub 用 pull request
    
方法2: 本地進行merge
    
    在 master 進行 git merge new-feature
    
### 好的 commit 訊息

1. 格式

    ![格式](https://i.imgur.com/ysMVrHk.png)

2. 主旨不超過50字 (通常1行)
    
3. 主旨用大寫開頭

4. 主旨不用加句點

5. 主旨句用祈使句 (命令句型用原型)

6. 內文72個字一行

7. 用內文解釋"為什麼"做這些修改

    what、how程式內就看的出來，留下why很重要

### 解決方案: Permission denied (publickey).

(1) 檢視shh key是否存在 (若存在跳到步驟3）

    ls ~/.ssh/

(2) 新建ssh key

    ssh-keygen -t rsa -C "GitHub user name"

(3) 將ssh key新增到ssh-agent

    1. 啟動ssh-agent    
    eval "$(ssh-agent -s)"
        
    2. 將ssh key新增到ssh-agent
    ssh-add ~/.ssh/id_rsa
        
(4) 將ssh key新增到GitHub賬號

settings --> SSH and GPG keys --> new SSH key

    Title隨便填寫
    
    "C:\Users\<username>\.ssh\id_rsa.pub" 的編碼複製貼上到key裡
    
    Add SSH key

<!-- -------------------------------------------------- -->
分版
---

### 分版觀念 (Master、Branch、Merge)

主幹（Master）與分支（Branch）是稱呼專案的主要版本和分支版本。

在GitHub上，通常第一個建立的專案版本會稱為Master版本。但對Git而言，開發專案的版本並無主幹（Master）與分支（Branch）的分別，每個分支都是等價關係，而開發者自行調整版本命名來區分。一般習慣將穩定版本稱主幹，其餘的變動、開發中版本則都稱作分支。

Branch是一個建立分支的Git指令，可將某個歷史版本複製一份，獨立成為另一個新的分支版本，而合併（Merge）指令剛好相反，則是把兩個不同的分支版本，合併到其中一個分支上。

![分版觀念](https://i.imgur.com/UvjCSS1.png)

### 分版手法 (Clone、Fork)

- 複製（Clone）指令是把專案在遠端儲存庫上的所有內容複製到本地，建立本機儲存庫及工作目錄
- 叉（Fork）指令是把別人專案的遠端儲存庫內容複製一份到自己的遠端儲存庫
    「就像是在餐桌上用叉子把盤子上的一塊肉叉到自己的盤子上」

### 資料同步 (Push、Pull、Pull Request)

開發者可以執行Pull取得其他人開放授權的遠端儲存庫上的程式碼，也可以將自己修改的程式碼Push到可存取的第三者遠端儲存庫上。透過推（Push）跟拉（Pull）指令，開發者就能互相分享原始碼。

- 推（Push）指令是把自己目前本機端儲存庫的相關檔案，上傳到遠端儲存庫
- 拉（Pull）指令是把遠端儲存庫的最新版本下載至自己的本機端，並將遠端分支合併到本地分支
    (Pull並不像Clone指令會下載完整專案各版本內容)
- Pull Request則是更主動地要求第三方開發者納入自己開發的程式，將本地端儲存庫上的程式碼，整併到對方的儲存庫上

<!-- -------------------------------------------------- -->
參考網址
---

[Git達人教你搞懂GitHub基礎觀念](https://www.ithome.com.tw/news/95283)
[專案時報錯Permission denied](https://www.796t.com/content/1544294526.html)

[GitHub Branch 策略 - 哪一種方式適合你?](https://ithelp.ithome.com.tw/articles/10261136?sc=iThelpR)
[Git版本恢復與分支管理](https://mropengate.blogspot.com/2015/11/git-git.html)

[影片清單: git教學系列](https://www.youtube.com/playlist?list=PLz-S_Wd1N3svV8XnuDM6CPaTCtQkk5SY4)
[Git 指令練習](https://learngitbranching.js.org/?locale=zh_TW)

<!-- -------------------------------------------------- -->