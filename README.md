# line-printer

`line-printer` is a program to print file's contents *only* in a single line
of output. It doesn't really have any significant uses, but it sure looks a
bit cool \^\_\^.

## Building

Run the following commands:

```
$ cd /intended/dir/for/this/repo
$ git clone https://github.com/richiesuper/line-printer
$ cd line-printer
$ make
```

## Usage

```
$ ./line-printer [FILE|-]
```

Example:

```
$ ./line-printer examplefile.txt
$ ./line-printer -
$ echo "Multi\\nLine\\nInput\\n" | ./line-printer -
```

## Warning

Make sure your stdin input or FILE's lines *always* ends with newline or
`line-printer` won't erase the output line.
