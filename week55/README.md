# 2023 / 10 / 04
- 開會內容
- 進度回報

# 本周進度報告
- 劉品宗
  - 完成後端debug(目前暫時沒有問題)
  - email驗證(等待可使用的smtp server)
  - 時序圖(還沒開始製作)

- 陳韋翰
  - 完成座標轉換功能 (有些許誤差)
    - 可以用 linear regression 改善
  - Rust
    - 用 Actix Web 作為校內導航功能的後端
    - 拆成 crate, module，也有寫 test
  - 校內導航加入前端 (進行中)
    - 導航剩下加入定位功能
    - 下訂單選地點時也可加入校內地圖

- 徐欣業
  - 前端架設、畫拓譜圖
  - 問題: 沒辦法將 nginx 導向 docker

# 下周目標
- 劉品宗
  - 等待email 有可以使用的帳號就可以直接上線
  - 時序圖

- 陳韋翰
  - 校內導航繼續寫
  - 將導航後端包 docker

- 徐欣業
  - 解決問題