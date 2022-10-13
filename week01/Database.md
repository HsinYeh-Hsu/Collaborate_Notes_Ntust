# 專題筆記: 資料庫
09/22 - 09/28, 2022

<!-- -------------------------------------------------- -->
資料庫的定義、類型和範例
---

### 資料庫是什麼

在最基本的定義中，資料庫是任何相關資訊的集合。

### 資料庫的用途

用來儲存和組織資料，以便使用者更容易管理和存取。
使用包含了一層管理工具的資料庫管理系統 (DBMS)，可以讓資料易於存取及保護。

### 資料庫類型

分為關聯式和非關聯式資料庫。

關聯式資料庫已高度結構化，結構化查詢語言(SQL)的程式設計語言。非關聯式資料庫則非常多樣化，支援各種不同的資料結構。因為許多非關聯式資料庫不使用SQL，因此通常稱為NoSQL資料庫。

NoSQL是為了解決以往關聯型資料庫所不擅長的部分而產生出來的。過去關聯型資料庫，可以應付各種任務，但隨著WEB2.0開始，許多服務需要處理大量的用戶請求。特化資料庫，更容易依照需求去擴充規模，NoSQL不再被限制成固定的表，開發者有更多彈性。

- 關聯式 (SQL)
    
    資料會組織成資料表，保存每個實體的相關資訊，並透過資料列和資料行呈現預先定義的類別。此結構化資料讓存取有效率又有彈性。
    
    例如: SQL Server、Azure SQL、MySQL、PostgreSQL、MariaDB

- 非關聯式 (NoSQL)

    儲存非結構化或半結構化的資料，針對要儲存之資料類型的特定需求，使用經過最佳化的儲存體模型。非關聯式資料庫可快速存取、更新及分析更大的分散式資料集合。
    
    例如: MongoDB、Azure Cosmos DB、DocumentDB、Cassandra、Couchbase、HBase、Redis、Neo4j

### 資料結構類型

資料表結構是關聯式資料庫結構，可將資料組織成資料列和資料行: 資料列包含實體而資料行包含實體屬性。寬型資料表 (或稱寬型資料行存放區)，使用具有空白屬性的疏鬆資料行，大幅增加您在資料表中可以擁有的資料行總數。因為有些空格是空的，所以寬型資料表是非關聯式資料庫結構的範例。

- 陣列
![](https://azurecomcdn.azureedge.net/cvt-52c494977aadfc830486f221326086e5b577f68114a1571049f851e95453de89/images/page/resources/cloud-computing-dictionary/what-are-databases/types-of-databases1.png)

- 連結清單
![](https://azurecomcdn.azureedge.net/cvt-52c494977aadfc830486f221326086e5b577f68114a1571049f851e95453de89/images/page/resources/cloud-computing-dictionary/what-are-databases/types-of-databases2.png)

- 二進位樹狀目錄 (階層式資料庫)

    樹狀結構會將元素組織成來自一個根節點的父/子關聯性節點的階層式資料庫。
![](https://azurecomcdn.azureedge.net/cvt-52c494977aadfc830486f221326086e5b577f68114a1571049f851e95453de89/images/page/resources/cloud-computing-dictionary/what-are-databases/types-of-databases3.png)

- 圖表 (節點非階層式網路)

    圖形結構會將元素組織成彼此之間有複雜關聯性的節點非階層式網路。
![](https://azurecomcdn.azureedge.net/cvt-52c494977aadfc830486f221326086e5b577f68114a1571049f851e95453de89/images/page/resources/cloud-computing-dictionary/what-are-databases/types-of-databases4.png)

- 雜湊表

    雜湊型結構會使用雜湊函式將索引鍵對應至值，藉由將索引指派給雜湊表，建立相關聯的資料。
![](https://azurecomcdn.azureedge.net/cvt-52c494977aadfc830486f221326086e5b577f68114a1571049f851e95453de89/images/page/resources/cloud-computing-dictionary/what-are-databases/types-of-databases5.png)

- 文件導向資料庫

    文件導向資料庫會將實體的資訊數量組織成單一物件 (文件)，與其他物件分開。物件不需要彼此對應，而且可以編輯單一物件，不會影響其他物件。
![](https://azurecomcdn.azureedge.net/cvt-52c494977aadfc830486f221326086e5b577f68114a1571049f851e95453de89/images/page/resources/cloud-computing-dictionary/what-are-databases/types-of-databases6.png)

### SQL vs. NoSQL

手機、網頁、遊戲，這類需要彈性、規模化、高性能的特性，或是在開發初期，用戶需求不明確，資料結構時常變動的情況下，NoSQL資料庫就很適合。缺點是沒有豐富的SQL語句可以使用，而不同種類的NoSQL，API的設計和使用也大不相同，需要花費額外的學習成本。
 
- SQL (嚴格定義)

    - 支持資料一致性，適合線上交易(資料改動完全一致且正確)
    - 表、行、列
    - ACID 提供機制校正資料和確保資料一致性
    - 提升單一的機器來達到效能提升(vertical scaling)

- NoSQL (更多彈性)

    - 適合訪問特定類型的資料，特化了特定資料的搜尋、存儲方式，有較低的延遲
    - 鍵值、文檔、圖、內存、搜索
    - 犧牲ACID的核心概念，追求BASE核心概念
    - 增加機器提升效能(horizontal scaling)
    
   
<!-- -------------------------------------------------- -->
參考資料
---

[資料庫是什麼?](https://azure.microsoft.com/zh-tw/resources/cloud-computing-dictionary/what-are-databases/)

[影片: 快速了解NoSQL](https://www.youtube.com/watch?v=zzDBxzlmHHU)

<!-- -------------------------------------------------- -->