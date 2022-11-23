# 專題筆記
11/17 ~ 11/23, 2022

### 平台分享

- [istaging](https://www.istaging.com/zh-tw/livetourGallery)
    - VR 線上編輯平台，可以加入文字、聲音、影片等等

- [線上博物館](https://virtual-museums.tw/)
  - [國立臺灣科學教育館](http://vr.kissscience.tw/)
  - [聽種子的故事](https://vr.ntm.gov.tw/2022Seed/)

### 學習 React

- [程式碼](https://github.com/wei06097/React-Practice1)

- [React | Web Dev Simplified](https://youtube.com/playlist?list=PLZlA0Gpn_vH_NT5zPVp18nGe_W9LqBDQK)

- [Reference VS Value In JavaScript | Web Dev Simplified](https://youtu.be/-hBJz2PPIVE)

<!-- ============================================================================= -->
### [React Hook](https://gcdeng.com/blog/react-hooks)

- [useState](https://youtu.be/O6P86uwfdR0)
  ```
  render (Virtual DOM) => Real DOM
  ```
  ```JavaScript
  import {useState} from 'react'

  // in Component Function
  const [state, setState] = useState(initialState)
  setState(newState)  // 更改state (render DOM)
  ```

<!-- ================================================== -->
- [useEffect](https://youtu.be/0ZJgIjIuY7U)
  ```
  取代生命週期，可用於綁定和移除監聽事件
  ```
  ```JavaScript
  import {useEffect} from 'react'

  // in Component Function
  useEffect(() => {
    // subscription
    const subscription = props.source.subscribe()
    return () => {
      // Clean up the subscription
      subscription.unsubscribe()
    };
  }, [props.source])
  ```

<!-- ================================================== -->
- [useRef](https://youtu.be/t2ypzz6gJm0)
  ```
  (很像 useState)

  1. 存放上一個 value，並在不同 render 中保持不變，且更改後並不會 re-render

  2. 為 <html tag> 加上 ref，可以方便抓到該物件 (refName.current)
  ```
  ```JavaScript
  import {useEffect, useRef} from 'react'

  // in Component Function
  const refContainer = useRef(initialValue) // {current: initialValue}
  useEffect(() => {
    if (refContainer.current == value) {
      // Do Something
    }
  }, [dependency])
  ```

<!-- ================================================== -->
- [useContext](https://youtu.be/5LrDIWkK_Bc)
  ```
  像是 components 的全域變數，不需要將 props 傳入每個 component
  ```

  ```JavaScript
  // in ThemeProvider.js
  import React, {useContext, useState} from 'react'

  const ThemeContext = React.createContext()
  const ThemeUpdateContext = React.createContext()

  export function useTheme() {
    return useContext(ThemeContext)
  }
  export function useThemeUpdate() {
    return useContext(ThemeUpdateContext)
  }

  export default ThemeProvider = function ({ children }) {
    const [darkTheme, setDarkTheme] = useState(true)
    function toggleTheme() {
      setDarkTheme(prev => !prev)
    }

    return (
      <ThemeContext.Provider value={darkTheme}>
        <ThemeUpdateContext.Provider value={toggleTheme}>
          {children}
        </ThemeUpdateContext.Provider>
      </ThemeContext.Provider>
    )
  }
  ```

  ```JavaScript
  // in App.js
  import Children from './components/Children'
  import {ThemeProvider} from './components/ThemeProvider'
  
  export default App = function () {
    return (
      <ThemeProvider>
        <Children />
      </ThemeProvider>
    )
  }
  ```

  ```JavaScript
  // in Children.js
  import {useContext} from 'react';
  import {useTheme, useThemeUpdate} from './ThemeProvider'

  export default Children = function () {
    const darkTheme = useTheme();
    const toggleTheme = useThemeUpdate()
    const themeStyles = {
      backgroundColor: darkTheme? '#333': '#ccc', 
      color: darkTheme? '#ccc': '#333', 
    }

    return (
      <>
        <button onClick={toggleTheme}>Toggle Theme</button>
        <div style={themeStyles}>Function Theme</div>
      </>
    )
  }
  ```

<!-- ================================================== -->
- [useReducer](https://youtu.be/kK_Wqx3RnHk)
  ```
  (很像 useState，但可以處理更複雜的情況)
  manage state and re-render component
  ```
  ```JavaScript
  import {useReducer} from 'react'

  function Init(initialValue) {
    return { count: initialValue };
  }

  function reducer(state, action) {
    switch (action.type) {
      case 'increment':
        return { count: state.count + 1 };
      case 'decrement':
        return { count: state.count - 1 };
      default:
        return state;
    }
  }

  export default App = function () {
    const [state, dispatch] = useReducer(reducer, initialValue, Init);
    return (
      <>
        Count: {state.count}
        <button onClick={() => dispatch({ type: 'decrement' })}>-</button>
        <button onClick={() => dispatch({ type: 'increment' })}>+</button>
      </>
    );
  }
  ```

<!-- ================================================== -->
- [useMemo](https://youtu.be/THL1OPn72vo)
  ```
  (類似 useCallback，但 return 的是 Obeject)

  1. 解決 Slow Function 造成的效能問題，但會增加記憶體使用
    (在 react 更新 state，會 re-render 整個 component)

  2. 解決 Referential Equality
    (當 dependency 改變時才會 re-create Obeject)
  ```
  ```JavaScript
  import {useMemo} from 'react'

  // in Component Function
  const case1 = useMemo(() => {
    return slowFunction(dependency)
  }, [dependency])

  const case2 = useMemo(() => {
    return {
      backgroundColor: dark? '#333': '#ccc', 
      color: dark? '#ccc': '#333', 
    }
  }, [dark])
  ```

<!-- ================================================== -->
- [useCallback](https://youtu.be/_AyFP5s69N4)
  ```
  (類似 useMemo，但 return 的是整個 Function)

  1. 解決 Slow Function 造成的效能問題

  2. 解決 Referential Equality
    (當 dependency 改變時才會 re-create Function)
  ```
  ```JavaScript
  import {useCallback} from 'react'

  // in Component Function
  const getItems = useMemo((incrementor) => {
    return [number + incrementor, number - incrementor]
  }, [number])

  getItems(parameters)
  ```

<!-- ============================================================================= -->