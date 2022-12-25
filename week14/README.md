# 專題筆記
12/22 ～ 12/26, 2022

### 學習 SQL
---

tables / keys
---

- 主鍵 (primary key)，使用一個或多個 primary key，讓 row 可以唯一

- 外鍵 (foreign key)，對應到另一個(或自己)表格的 primary key

- primary key 也可以是 foreign key，看資料庫的設計和複雜度

![](https://i.imgur.com/OtICooA.png)

創建資料庫
---
- 關鍵字通常會用大寫，但不強制
- 命名名稱通常會用反引號包起來，避免與關鍵字衝突
```mySQL=
/* 建立資料庫 */
CREATE DATABASE `database`;

/* 顯示所有資料庫 */
SHOW DATABASES;

/* 刪除資料庫 */
DROP DATABASE `database`;

/* 使用資料庫 */
USE `database`;
```

創建表格
---

- 常用資料型態
```=
- 整數
INT

- 有小數點的數 (m=3, n=2) => 2.33
DECIMAL(m,n) 

- 字串
VARCHAR(n)

- Binary Large Object (圖片、影片、檔案)
BLOB

- 'YYYY-MM-DD' 日期
DATE

- 'YYYY-MM-DD HH:MM:SS' 紀錄時間
TIMESTAMP
```
- 範例
```mySQL=
/* 創建表格 */
CREATE TABLE `student`(
    `student_id` INT PRIMARY KEY,
    `name` VARCHAR(20),
    `major` VARCHAR(20)
);

/* 讀取表格 */
DESCRIBE `student`;

/* 刪除表格 */
DROP TABLE `student`;

/* 增加表格屬性 */
ALTER TABLE `student` ADD `gpa` DECIMAL(3, 2);

/* 刪除表格屬性 */
ALTER TABLE `student` DROP COLUMN `gpa`;
```

限制
---
- 常用限制
```=
/* 預設值 */
DEFAULT '內容'

/* 不可為空 */
NOT NULL

/* 必需唯一 */
UNIQUE

/* 自動遞增 */
AUTO_INCREMENT
```
- 範例
```mySQL=
CREATE TABLE `student`(
    `student_id` INT AUTO_INCREMENT,
    `name` VARCHAR(20) NOT NULL, 
    `major` VARCHAR(20) NOT NULL DEFAULT 'history',
    PRIMARY KEY(`student_id`)
);
```

插入/修改/刪除 資料
---
- 條件判斷
    - 等於 = 
    - 不等於<>
```mySQL=
/* 關閉預設更新模式 */
SET SQL_SAFE_UPDATES = 0;

/* 插入資料 */
INSERT INTO `student` VALUES(1, 'naruto', 'ninja');
INSERT INTO `student`(`name`, `major`) VALUES('jashinchan', 'akuma');

/* 修改資料 */
UPDATE `student`
SET `name` = 'hebi', `major` = 'kuzu'
WHERE `student_id` = 2;

/* 刪除資料 */
DELETE FROM `student`
WHERE `student_id` = 2 AND `name` = 'hebi';

/* 顯示表格內的所有資料 */
SELECT * FROM `student`;
```

取得資料
---
- ASC 低到高
- DESC 高到低
- LIMIT `number`
- ORDER BY `key`
```mySQL=
SELECT `name`, `major`
FROM `student`
WHERE `major` = 'ninja';

SELECT *
FROM `student`
WHERE `major` IN('ninja', 'history');

SELECT *
FROM `student`
ORDER BY `name` DESC, `student_id` ASC
LIMIT 3;
```

參考資料
---

- [SQL 3小時初學者教學](https://www.youtube.com/watch?v=gvRXjsrpCHw)