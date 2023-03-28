# 计算器使用说明

## 编译

``` bash
cmake .
make build/.
```


## 使用

```bash
Calculator.exe "1+2"
```


## 错误提示

"(-1" "(-1-)" 会报错 expect ')' at 3
"1#1" 会报错 unkown operator '#'
"(1+1" 会报错 illegal formula

