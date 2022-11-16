# 專題筆記: Capstone
11/10 ~ 11/16, 2022

### 進度

- 嘗試做斷線後重連處理(失敗)
- 增加權限控制系統
- 分房間

### 目前功能統整

- 建立或加入房間

- 顯示成員及人數

    - 分為主持人、說話者、聽眾三個級別 (L1、L2、L3)
    - 按照級別進行排列 (L3)
    - 說話時名字顏色會變 (L3)
    - 可以分別控制聽到的音量大小 (L3)
    - icon 顯示狀態，耳機、麥克風開啟、麥克風關閉 3 種 (L3)
    
- 權限系統

    - 主持人 : 可以給聽眾權限，使其成為說話者，也可以收回說話者權限。
    - 說話者 : 能做到更多事 (說話、畫面分享、控制音樂機器人 etc.)
    - 觀眾 : 可以向主持人申請權限

- 主要功能

    - (L2) 可以開啟相機、螢幕分享、麥克風(可調整是否降噪)
    - (L3) 可以觀看直播
    - (L3) 顯示名字在影片右下角(點擊可以全螢幕)
    - (L3) 可以調整成影片排版(大小)，顯示1個、4個...
    - (L3) 可以改變影片位置的順序
    
- 聊天室及音樂機器人

    - 聊天室 : 有自動刷新等人性化設計 (L3)
    - 音樂機器人 : 能控制音樂音量 (L3)
            
            -------------------- (L2)
            播放音樂
            play YouTube網址
            play 關鍵字
            
            暫停播放
            pause
            
            繼續播放
            resume
            
            跳過目前歌曲
            skip
            
            重複目前歌曲
            loop
            
            取消重複歌曲
            unloop
            
            清除歌單
            clear
            
            -------------------- (L3)
            查看歌單
            list
            
            清除訊息
            cls
    
            查看所有指令
            yt

### 影片

- [斷線處理-1 (失敗)](https://youtu.be/AwuE6ZNH7XA)
- [斷線處理-2 (失敗)](https://youtu.be/fAILDJUemDI)

### 詳細內容

- Demo 影片 ([press me](https://youtube.com/playlist?list=PL4Bl81xxXc5fY6oM2zCXmyQQEHVuhgm63))
- Note ([press me](https://hackmd.io/@wei06097/HJTCfD-Vi))
- Code ([press me](https://github.com/wei06097/Capstone-LiveStreaming))