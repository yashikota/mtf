# mtf

[English](./README.md) | [Japanese](./README.ja.md)  

## Name

enc - Encodes input text using the Move-To-Front transform  
dec - Decode text encoded by Move-To-Front

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
    Specify the name of the output file.  
    If not specified, the output will be the name of the input file.  

## Usage

### Encode

```sh
./enc test.txt
```

The `test.txt` is MTF transformed and `test.mtf` is generated.  

```sh
./enc -o output.mtf input.txt
```

The `input.txt` is MTF transformed and `output.mtf` is generated.  

### Decode

```sh
./dec test.mtf
```

The `test.mtf` is decoded and `test.txt` is generated.  

```sh
./dec -o output.txt input.mtf
```

The `input.mtf` is decoded and `output.txt` is generated.  

## Build

```sh
make
```

The `enc` and `dec` are created in the current directory.  

## Example

### Original

```txt
128
128
128
128
128
128
128
128
128
128
128
128
255
255
255
255
255
255
255
255
255
255
255
255
0
255
255
128
128
128
0
255
128
128
128
128
```

### Transformed

```txt
128
1
0
0
0
0
0
0
0
0
0
0
255
1
0
0
0
0
0
0
0
0
0
0
2
0
0
2
1
0
2
2
0
0
0
0
```
