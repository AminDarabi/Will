# Will
'WILL' helps people making decision in dilemmas.
you give 'WILL' the choices and it will choice one of them for you (randomly).

# INSTALL

you can install the will on linux/mac/unixlikes like this:

    $ git clone https://github.com/AminDarabi/will.git
    $ cd will
    $ make
    $ sudo install

# USAGE

you can use 'Will' to choice your meal and get a random choice as simple like this (result, pizza, may various):

    $ will pizza burger
    pizza

`--file <file>` option|argumant could be use to read choices from <file>.

    $ will --file foods.txt
    
in case there is no choices in argumants and there is no file 'Will' will read from stdin, until you enter `--1`, `--end`, or EOF.

    $ will
    pizza
    burger
    --end
    
 or
 
    $ will < foods.txt
    
you can also use `--input` to enable stdin reading even when there is file(s) or choices in argumants.

    $ will pizza burger --file vegan_foods.txt --input
    kebab
    --end
 
 or
 
    $ will pizza burger --file vegan_foods.txt --input < classic_foods.txt
    
`--endline` option|argumant could be use to seprate choices in files or stdin by newline.
an example of using 'Will' with this option and 'Will' answer is:
    
    $ will --endline < student_list.csv
    9912345,Amin Darabi,CS
or
    $ will --endline --file student_list.csv
    9912345,Amin Darabi,CS

if you want to determines order of doing your choices you can use `--shuffle` option|argumant.

    $ will --shuffle call_my_friend take_a_shower
