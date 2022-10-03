# 專題筆記: 網路通訊協定
09/29 - 10/05, 2022

<!-- -------------------------------------------------- -->
HTTPS
---

超文本傳輸安全協定(Hypertext Transfer Protocol Secure)，簡稱HTTPS，建立在HTTP的基礎上，不過多了更安全的SSL/TLS來加密封包資料。

    SSL
    
    利用非對稱加密演算來對通訊方做身分認證，
    之後交換對稱密匙作為會談密匙（Session key）。
    
    這個會談密匙是用來將通訊兩方交換的資料做加密，
    保證兩個應用間通訊的保密性和可靠性，
    使客戶與伺服器應用之間的通訊不被攻擊者竊聽。

### HTTP 組成結構

分為HTTP Request與HTTP Response這兩個大項目。網頁上的資訊，其實就是由許多request跟response構成，兩者內容都分成header(額外資訊)與body(主要內容)。

![組成結構](https://miro.medium.com/max/750/1*-8Avv9KZTYRc9Pi_hZUROQ.png)

### Request

從客戶端發出HTTP Request時，會定義一些資訊。瀏覽網頁通常會使用GET方法，Message Body為空。若客戶端要送出資料，則會使用POST方法將資料送進Message Body，提交給某個指定的URL，進而建立資料或更新資料。

    Request Method 常用的幾個動作，其中 GET 和 POST 更為常見
    
    - GET：讀取資料
    - POST：新增資料（常搭配 form 標籤使用）
    - PATCH：修改資料
    - PUT：修改資料（若該筆資料不存在，則自動新增資料）
    - DELETE：刪除資料
    
GET 和 POST 請求的區別
 
    - GET：向指定的資源要求資料，類似於查詢操作。
    
    資料傳遞方式：將引數由 URL 帶至 Server 端
    安全性：較 POST 不安全，因為傳遞的引數會在URL上顯示
    例如：讀取連結或圖片
    
    
    - POST：將要處理的資料提交給指定的資源，類似於更新操作。
    
    資料傳遞方式：將引數放在 request body 中傳遞
    安全性：較 GET 安全，適合用於隱密性較高的資料
    例如：會員登入系統

### Response

伺服器端回傳HTTP Response時，也會定義一些資訊。

    Status Code
    
    - 1XX 訊息類 (收到請求，請求者繼續執行操作)
    - 2XX 成功類 (操作被成功接受並處理)，例如：200 成功回應
    - 3XX 重定向類 (需進一步操作才能完成)，例如：301 成功轉向
    - 4XX 客戶端錯誤類 (請求語法錯誤或無法完成請求)，例如：404 找不到資源
    - 5XX 伺服器錯誤類 (後端的問題)，例如：500 伺服器錯誤
    
    
     Content-Type 
     
     定義回應格式
     例如 text/html、text/plain、application/json
     客戶端才會知道該如何打開訊息
     
     
     Response Body
     
     許多程式碼檔案，最終渲染成畫面給使用者觀看

<!-- -------------------------------------------------- -->
OSI Model & TCP/IP Model
---

    應用: 各種網路服務介面
    表示: 格式編碼、加解密、壓縮
    會議: 建立連線
    
    傳輸: 訊息 -> 區段 檢查資料傳送是否遺失
    網路: 區段 -> 封包 選擇封包最佳傳輸路徑
    
    資連: 封包 -> 訊框 檢查資料是否錯誤
    實體: 透過網路設備傳送訊號
    
![OSI and TCP/IP](https://i.imgur.com/ODT31o2.png)
![封包階層](https://i.imgur.com/Mtm61cD.png)

<!-- -------------------------------------------------- -->
TCP & UDP
---

兩者皆為傳輸層（Transport Layer）協定提供不同主機之間的資料傳輸及控制。

### TCP

傳輸控制協定 (Transmission Control Protocol)，是一種可靠的資料傳輸，因此大部分的網路協定都是建立在TCP上面，透過「三次握手」確認建立一個連接。多用於要求可靠傳輸的服務，例如電子郵件、網頁瀏覽、檔案傳輸。

    1. 
    TCP為每個封包分配一個唯一的識別碼和一個序號，
    這些號碼能讓接收端識別封包的完整性，以及封包的順序。
    
    2.
    當接收端收到封包後，如果順序正確，
    會向發送端傳送一個確認信號（Acknowledgement），
    以此確認接收端已經收到封包。
    
    3. 
    發送端傳送另一個封包。
    
    4.
    如果封包遺失或發送順序錯誤，接收端會保持沈默，
    不發送確認信號。這表示發送端需要重新傳送封包。
    
    *** 三次握手 ***
        
       A：在嗎？
       B：在阿。
       A：收到！
       
    ****************

![TCP握手](https://i.imgur.com/SIvFV3n.png)

### UDP

用戶資料包協定(User Datagram Protocol)，流量是不受規範的，需要快速、重複傳送資料的情況會使用UDP，相對而言也較不穩定，多用於即時服務，例如串流媒體、網路電話、網路遊戲。

### TCP 跟 UDP 比較

|  | TCP | UDP |
| -------- | -------- | -------- |
|可靠性|可靠|不可靠|
|速度|慢|快|
|傳輸方式|封包按順序傳輸|封包以串流方式傳輸|
|錯誤檢查與修正|有|無|
|壅塞控制|有|無|
|確認|有|只有檢查碼|

![簡易了解架構](https://miro.medium.com/max/750/1*Z7v4uPI663Gyk_DKOxvxZA.png)

<!-- -------------------------------------------------- -->
MQTT
---

最初代表的意思是Message Queueing Telemetry Transport（訊息佇列遙測傳輸），MQTT協定的訊息內容很精簡，非常適合用於處理器資源及網路頻寬有限的物聯網裝置。

### MQTT 跟 HTPP 的比較

底層都是TCP/IP，可以沿用既有的網路架構和設備，差別在網路上流通的「訊息格式」以及應用程式的「處理機制」不同。

### 訊息格式

    - HTTP標頭: 採用文字描述
        
    - MQTT標頭: 採用數字編碼，長度只佔2Bytes，後面跟著訊息的主題（topic）和內容（payload）

![MQTT格式](https://swf.com.tw/images/books/IoT/MQTT/mqtt_message_format.png)

### 訊息傳輸協定

    基於「發布∕訂閱」機制
        
    代理人（broker）是個伺服器軟體
    向伺服器發送主題的一方是發布者（publisher）
    從伺服器獲取主題的一方則是訂閱者（subscriber）

![發布∕訂閱](https://i.imgur.com/O2ZgVpY.png)

<!-- -------------------------------------------------- -->
Websocket
---

WebSocket 是一種網路傳輸協定，可在單個TCP連接上進行全雙工通訊，位於OSI模型的應用層。

    Client可以透過此協定與Server做溝通，而他和一般https不同的是，
    只需透過一次連結便能保持連線，不必再透過一直發送Request來與Server互動。
    
    傳送資料的方式是雙向的，Client端可以像Ajax一樣做請求，
    Server端也能主動發送Client所需要的資料，使Client和Server之間的資料交換變得簡單。

### Websocket 跟 HTPP 的比較

- 相同

    - 都是基於TCP的應用層協議
    - 都使用Request/Response進行連接的建立
    - 在連接的建立過程中對錯誤的處理方式相同，這個階段WS可能返回和HTTP相同的狀態碼
    - 都可以在網路中傳輸資料

- 不同

    - WS使用HTTP來建立連接，但是定義了一系列新的header，這些在HTTP中並不會使用
    - WS是HTML5中的協定，支援長久連接，而Http協定不支援長久連接
    - WS的連接不能通過中間人來轉發，它必須是一個直接連接
    - WS連接建立之後，通信雙方都可以在任何時刻向另一方發送資料
    - WS連接建立之後，資料的傳輸使用幀來傳遞，不再需要Request消息
    - WS的資料幀有序

### Websocket 的優劣

- 優

    - 效率上有多方面的提升
- 劣

    - 伺服器長期維護常連接需要一定成本
    - 瀏覽器支援程度不一
    - 網路限制大，需要處理好斷線重連問題

### 應用場合

通訊領域應用多，比如社交聊天、彈幕、多玩家遊戲、協同編輯、股票基金即時報價、體育實況更新、視訊會議/聊天、基於位置的應用、線上教育、智慧家居等需要高即時的場景。

<!-- -------------------------------------------------- -->
RPC (分散式系統溝通方法)
---

遠端程序呼叫(Remote Procedure Call)，是將本地程式的function或是物件裡的method外顯出來，利用TCP/UDP/HTTP各種網路通訊方法，讓別台機器上面運行的程式可以透過網路呼叫你的這個function或是method。

近來網路應用非常普遍，常需要將某些專屬功能以一個獨立的設備來實現，以增加系統的效率。最常見的是Database Server所提供的網路之間資料處理工具，資料的查詢（Query）、插入（Insert）、更新（Update）、刪除（Delete）等等，這些處理工具都是透過RPC來實現。


- 目的

    - 提供一種分散式系統不同Components溝通的方法
    - 可以隱藏通訊的方法，對Client來說就是呼叫function

### 架構流程

1. client呼叫client stub。這個呼叫是在本地，並將呼叫參數push到stack中
2. client stub將這些參數包裝，並通過系統呼叫傳送到伺服器端機器，打包的過程叫marshalling（常見方式：XML、JSON、二進位編碼）
3. 客戶端本地作業系統傳送資訊至伺服器（可通過自訂TCP協定或HTTP傳輸）
4. 伺服器系統將資訊傳送至server stub
5. server stub解析資訊，該過程叫unmarshalling
6. server stub呼叫程式，並通過類似的方式返回給客戶端

![RPC架構流程](https://i.imgur.com/0fWDtpA.png)

<!-- -------------------------------------------------- -->
參考資料
---

[何謂 HTTP 傳輸協定](https://medium.com/pierceshih/%E7%AD%86%E8%A8%98-%E4%BD%95%E8%AC%82-http-%E5%82%B3%E8%BC%B8%E5%8D%94%E5%AE%9A-1d9b5be3fd24)

[影片: 網路為什麼要分層](https://www.youtube.com/watch?v=oBanE8HGtww)

[網路基礎概論 - HTTP 協定、TCP/IP、API](https://hackmd.io/@Heidi-Liu/note-net101)

[TCP 和 UDP 是什麼：簡單的說明](https://nordvpn.com/zh-tw/blog/tcp-udp-bijiao/)

[MQTT教學（一）：認識MQTT](https://swf.com.tw/?p=1002)

[WebSocket 讓前後端沒有距離](https://medium.com/enjoy-life-enjoy-coding/javascript-websocket-%E8%AE%93%E5%89%8D%E5%BE%8C%E7%AB%AF%E6%B2%92%E6%9C%89%E8%B7%9D%E9%9B%A2-34536c333e1b)

[websocket 優缺點、應用場景以及與HTTP協議的異同](https://blog.csdn.net/qq_39903567/article/details/115385466)

[RPC 簡介](http://www.tsnien.idv.tw/Internet_WebBook/chap9/9-1%20RPC%20%E7%B0%A1%E4%BB%8B.html)

[遠端程序呼叫](https://zh.wikipedia.org/zh-tw/%E9%81%A0%E7%A8%8B%E9%81%8E%E7%A8%8B%E8%AA%BF%E7%94%A8)

[分散式系統溝通的方法 - RPC](https://ithelp.ithome.com.tw/articles/10223580)

<!-- -------------------------------------------------- -->