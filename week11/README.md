# 第11周筆記
[TOC]
### Windows 一堆一堆奇奇怪怪的BUG
### Use Ubuntu
- Reason: Because there are very very much bug or env. need to fix or change in windows.
- [Set up Ubuntu](https://adersaytech.com/practical-software/ubuntu-install-tutorial.html)
    - [Rufus](https://rufus.ie/zh_TW/)
    - [AHCI](https://m.mobile01.com/topicdetail.php?f=490&t=3848657)
        - Because we can't use raid to install ubuntu.
        - windows  only can use safety mode.
    - [Close the safety mode](https://jingyan.baidu.com/article/870c6fc37c47fef13fe4be8e.html)
        - But after doing this I need to go to Bios to set again...
### Set up python and django
- [Python](https://phoenixnap.com/kb/how-to-install-python-3-ubuntu)
- [Django](https://www.youtube.com/watch?v=6XrDPWb3HGk&ab_channel=TechWebDocs)
    - run server: python manage.py runserver 8080
- Django
    - Django template language(模板)
        - It is dynamic to change
        - ![](https://i.imgur.com/hpU2yzG.png) 
    - add two sum
        - ![](https://i.imgur.com/cS2kAz6.png)
        - res= num1 +num2 have some problem
    - Http get & post
        - ![](https://i.imgur.com/UwBv5GY.png)
    - MVT(model view templete )
        - ![](https://i.imgur.com/BZNLU9U.png)
    - static file 
        - ![](https://i.imgur.com/Boest7x.png)
        - ![](https://i.imgur.com/NNB7SPU.png)
### 資料結構作業
- ![](https://i.imgur.com/cZ9QJVY.png)
- Step:
    - Build a binary tree.
        - easy to find the lowest value.
        - can use ***inorder traversal*** to print out ***increasing order***
    - Compute the height of a binary tree.
        - ![](https://i.imgur.com/JKQ7PA9.png)
        - recursive