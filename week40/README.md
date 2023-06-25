# 06/21 ~ 06/27, 2023

- 了解 Redux-Toolkit 狀態管理器 
    - 使用 redux-toolkit 保存狀態
    - 使用 redux-persist 將狀態存到 localStorage/ sessionStorage
    - [測試程式](https://github.com/wei06097/React-Practice/tree/react-redux-test1)

- 困難 
    - 遇到問題
        - react-router 在切換路由時候，不會保存頁面的狀態 (keep-alive)
    (ps. vue-router 有這個功能)
    - 解決辦法
        - 使用其他元件庫替換掉 react-router，像是 react-kepper, react-activation, react-router-cache-route [(參考文章)](https://www.jb51.net/article/272253.htm)
        - 自己改造 react-router [(參考文章)](https://zhuanlan.zhihu.com/p/52693438?utm_id=0)
        - 使用 redux 這類的狀態管理器，當切回去之前的路由後，再把狀態復原
    - 最後方案
        - 使用 redux-toolkit，但是手動保存狀態會比較花時間。

- 進度
    - 將原先程式碼改使用 redux-toolkit 和 redux-persist
        - 登入/註冊
        - 瀏覽賣場
        - 商品管理
        - 首頁
    - 增強 UX
        - 圖片載入的 loading 提示
        - 增加資料處理時的 loading 圖示並 disable 相關按鈕