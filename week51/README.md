# 09/07 ~ 09/13, 2023

- 規劃校內導航流程
- 接訂單 API
- 接 WS
    - 即時通訊部分由原先使用 Socket.IO 改使用瀏覽器的 WebSocket API
    - 跟 Django 測試 WebSocket 基本功能
    - 在 Django 發生 WebSocket Reject
        - 推測是 origin 的原因 (未解決)
        - `127.0.0.1` 〇
        - `localhost` ✕ 
        - `192.168.244.130` ✕
