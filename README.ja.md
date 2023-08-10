# mtf

[English](./README.md) | [Japanese](./README.ja.md)  

## Name

enc - 入力されたテキストをMove-To-Front法で符号化  
dec - Move-To-Front法で符号化されたテキストを復号

## Synopsis

```sh
./enc [OPTION] FILE
```

```sh
./dec [OPTION] FILE
```

## Description

## Option

-o  
    出力するファイルの名前を指定します。  
    指定しなければ入力ファイル名で出力されます。  

## Usage

### Encode

```sh
./enc test.txt
```

`test.txt`がMTF法で符号化され、`test.mtf`が生成されます。  

```sh
./enc -o output.mtf input.txt
```

`input.txt`がMTF法で符号化され、`output.mtf`が生成されます。  

### Decode

```sh
./dec test.mtf
```

`test.mtf`が復号され、`test.txt`が生成されます。  

```sh
./dec -o output.txt input.mtf
```

`input.mtf`が復号され、`output.txt`が生成されます。  

## Build

```sh
make
```

カレントディレクトリに`enc`と`dec`が生成されます。  
