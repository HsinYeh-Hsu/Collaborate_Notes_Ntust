# 專題筆記
12/22 ～ 12/26, 2022

### 進度
- 學習 SQL

### 筆記
---

基本操作
---

### tables / keys

- `主鍵` `primary key`，可使用一個或多個 primary key
- `外鍵` `foreign key`，對應到另一個(或自己)表格的 primary key
- primary key 也可以是 foreign key，看資料庫的設計和複雜度

![](https://i.imgur.com/OtICooA.png)

### 創建資料庫

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

### 創建表格

- `INT` 整數
- `DECIMAL(m,n)` 有小數點的數 (總位數，小數點位數)
- `VARCHAR(n)` 字串
- `BLOB` Binary Large Object (圖片、影片、檔案)
- `DATE` 日期 `'YYYY-MM-DD'`
- `TIMESTAMP` 紀錄時間 `'YYYY-MM-DD HH:MM:SS'`

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

### 限制

- `DEFAULT` 預設值
- `UNIQUE` 必需唯一
- `NOT NULL` 不可為空
- `AUTO_INCREMENT` 自動遞增


```mySQL=
CREATE TABLE `student`(
    `student_id` INT AUTO_INCREMENT,
    `name` VARCHAR(20) NOT NULL, 
    `major` VARCHAR(20) NOT NULL DEFAULT 'history',
    PRIMARY KEY(`student_id`)
);
```

### 插入/修改/刪除 資料

- `=` 等於 
- `<>` 不等於

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

### 取得資料

- `ASC` 低到高
- `DESC` 高到低
- `LIMIT` 限制資料數量
- `ORDER BY` 排序
- `DISTINCT` 不重複

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

應用 (公司)
---
先將表格畫出來，並標示清楚 primary key、foreign key、attribute。

### 建立表格

- 部門、員工
```mySQL=
create table `employee`(
    `emp_id` int,
    `name` varchar(20),
    `birth_date` date,
    `sex` varchar(1),
    `salary` int,
    `branch_id` int,
    `sup_id` int,
    primary key(`emp_id`)
);

create table `branch`(
    `branch_id` int,
    `branch_name` varchar(20),
    `manager_id` int,
    primary key(`branch_id`),
    foreign key(`manager_id`) references `employee`(`emp_id`) on delete set null
);

alter table `employee`
add foreign key(`sup_id`)
references `employee`(`emp_id`)
on delete set null;

alter table `employee`
add foreign key(`branch_id`)
references `branch`(`branch_id`)
on delete set null;
```
- 客戶
```mySQL=
create table `client`(
    `client_id` int,
    `client_name` varchar(20),
    `phone` varchar(20),
    primary key(`client_id`)
);

create table `works_with`(
    `emp_id` int,
    `client_id` int,
    `total_sales` int,
    primary key(`emp_id`, `client_id`),
    foreign key(`emp_id`) references `employee`(`emp_id`) on delete cascade,
    foreign key(`client_id`) references `client`(`client_id`) on delete cascade
);
```

### 新增資料

- 部門、員工
```mySQL=
/* employee 表格內未有資料， 將 foreign key 設定成 NULL */
insert into `branch` values(1, '研發', null);
insert into `branch` values(2, '行政', null);
insert into `branch` values(3, '資訊', null);

insert into `employee` values(206, '小黃', '1998-10-08', 'F', 50000, 1, null);
insert into `employee` values(207, '小綠', '1985-09-16', 'M', 29000, 2, 206);
insert into `employee` values(208, '小黑', '2000-12-19', 'M', 35000, 3, 206);
insert into `employee` values(209, '小白', '1997-01-22', 'F', 39000, 3, 207);
insert into `employee` values(210, '小蘭', '1925-11-10', 'F', 84000, 1, 207);

/* 最後再更新原先設定成 NULL 的資訊 */
update `branch`
set `manager_id` = 206
where `branch_id` = 1;

update `branch`
set `manager_id` = 207
where `branch_id` = 2;

update `branch`
set `manager_id` = 208
where `branch_id` = 3;
```

- 客戶
```mySQL=
insert into `client` values(400, '阿狗', '254354335');
insert into `client` values(401, '阿貓', '25633899');
insert into `client` values(402, '旺來', '45354345');
insert into `client` values(403, '露西', '54354365');
insert into `client` values(404, '艾瑞克', '18783783');

insert into `works_with` values(206, 400, 70000);
insert into `works_with` values(207, 401, 24000);
insert into `works_with` values(208, 400, 9800);
insert into `works_with` values(208, 403, 24000);
insert into `works_with` values(210, 404, 87940);
```

參考資料
---

- [SQL 3小時初學者教學](https://www.youtube.com/watch?v=gvRXjsrpCHw)