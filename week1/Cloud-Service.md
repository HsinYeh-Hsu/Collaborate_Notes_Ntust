# 專題筆記: 伺服器、雲服務
09/22 - 09/28, 2022

<!-- -------------------------------------------------- -->
雲服務
---

雲服務是將電腦運算所需要的硬體和軟體資源，透過互聯網遠程使用，而不需要自備電腦或機房。白話的說，就是去租用別人的電腦。

傳統 IT 要建立網站伺服器，需要自行購買電腦硬體、網路設備、租用機房實體空間等等，在開站前就必須投資大筆的硬體成本。近年來的雲服務就像水電等公共基礎設施，用多少算多少，不需要自己蓋電廠或凈水場。

### 雲服務類型 (Iaas、Pass、Saas)

- Iaas 類型的雲服務，你可以租到一臺有最高權限的虛擬機，可以隨你的意願安裝任何軟體。
- Pass 類型的雲服務則是提供固定的程序執行環境，支援特定的程式語言和框架，只要將程式上傳到平臺上就可以執行。
- Saas 類型的雲服務只能執行特定軟體，SaaS軟體算是近年來的軟體趨勢(像是Office 365)。

| Iaas | Pass | Saas |
| -------- | -------- | -------- |
| AWS、 Microsoft Azure、 Linode | Heroku、IBM Bluemix | Tower、Github |

![比較圖](https://i.imgur.com/yNHHkev.png)


<!-- -------------------------------------------------- -->
Heroku
---

- Heroku 是一個平台即服務(PaaS)，可自行在Heroku平台開發和佈署各種網站，好處是減少維護管理系統底層的成本，也透過簡單的介面來調整需要的硬體設備等級及資源，選擇適合自己的等級做升級。Heroku操作相當簡單，可以讓開發者初期專心的開發程式，而不用煩惱管理機器或硬體維護。若網路流量變高，那Heroku就不太適合，必須改用其他的PaaS平台。

- 目前Heroku 提供了大家一個以 Debian為基礎的平台架設管理，並支援Rudy、Java、Node.js、Scala、Clojure及Python等程式語言。

        平台即服務（Platform as a Service, PaaS）是提供運算平台與解決方案服務

        PaaS提供使用者將雲端基礎設施部署與建立至用戶端，或者藉此獲得使用程式語言、程式庫與服務。
        使用者不需要管理與控制雲端基礎設施（包含網路、伺服器、作業系統或儲存），
        但需要控制上層的應用程式部署與應用代管的環境。

開發出一個軟體後，若希望大家都能使用到該服務，可以將軟體放到Heroku上。
如此一來，大家就可以像瀏覽網站一樣，在瀏覽器中輸入URL就可以存取到你所提供的服務。

### 原理

- 為了讓應用程式能夠正常的運作，Heroku必須準備(虛擬的電腦)，我們稱之為 Dyno。在Heroku 上，我們可以將Dyno想成虛擬機器，這些虛擬機器將會為應用程式提供運算資源，好讓應用程式能夠被正常執行。

- 特別的是，我們以為應用程式是部署在Heroku上，然而實際上，應用程式是被部署到AWS(Amazon Web Service)上。

        AWS是一個「基礎設施即服務」(Infrastructure as a Service, IaaS)的提供商

        IaaS的提供商經常會在世界各地購買大面積的土地，興建資料中心(Data Center)，
        就是我們常說的雲端(Cloud)。因為有這些IaaS提供商，
        我們在儲存檔案時不需要自己購買儲存設備，只需要上傳到雲端即可。

Heroku扮演開發者與IaaS之間的橋樑！

<!-- -------------------------------------------------- -->
Linode
---

- Linode是一間美國的虛擬專屬主機(VPS, Virtual Private Server)提供商。

- Linode提供的VPS全都是運行Linux作業系統，支援Arch Linux、CentOS、Debian、Fedora、Gentoo、Ubuntu和openSUSE等主流Linux發行版。

        VPS, 屬於IaaS
        
        VPS的優點在於可以按需購買，不必花費獨立伺服器的高昂費用。
        VPS有可以保證的資源（CPU、記憶體等），不會有over selling。

<!-- -------------------------------------------------- -->
ngrok
---

- ngrok 是一個反向代理，通過在公共的端點和本地運行的Web服務器之間建立一個安全的通道。 

- ngrok可捕獲和分析所有通道上的流量，便於後期分析和重放。

### 使用理由

- 測試或是debug方便！

- 若是開發網頁或是機器人，會很省時間。

正常要讓一個網站佈署到網上時，提供給測試人員或是其他工作夥伴，需要找一個正在運行的web服務器，還需要部署程式碼上去，測試結束後，再將此網站刪除。

但只要安裝了ngrok，在本地端執行，他會給一串網址，直接透過這個網址就能讓他人順利連接到本地端架設好的網站。
    
<!-- -------------------------------------------------- -->
參考網址
---

[Linux 雲端伺服器部署運維](https://ihower.tw/rails/fullstack-deployment-cloud.html)
[Iaas、Pass、Saas 傻傻分不清楚](https://dotblogs.com.tw/007_Lawrence/2017/08/21/155203)

[HeroKu 平台介紹](https://www.wpgdadatong.com/tw/blog/detail/40292)
[Heroku 是什麼 ?! 與 AWS 的差異?](https://www.potatomedia.co/post/8b92aa34-cd75-4e8d-9d39-c0617ee93573)

[Linode 簡介](https://www.newton.com.tw/wiki/linode/1222795)
[VPS 主機](https://host.com.tw/VPS%E4%B8%BB%E6%A9%9F)

[Linode vs Heroku | Secrets Unlocked](https://blog.back4app.com/linode-vs-heroku/)
[【ngrok 教學】 webhook 直接在本地端測起來，Debug沒煩惱！](https://learn.markteaching.com/ngrok-webhook/)

<!-- -------------------------------------------------- -->