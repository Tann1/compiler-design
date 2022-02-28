# compiler-design 

SJSU College students taking CMPE152 in spring of 2022 together.
We're using github as a collaborative tool for this project based class. 
Group Members: Kcirde Santos, George Dominise, Syed Quadri, and Tanishq Gadkari

## Basic git stuff to follow
- please make sure to work in your local branch after pulling from main
```
git pull origin main
git checkout -b <your name>
git branch
```
- Before doing a pull request verify consult with the group please.
- If you upload your local branch to remote make sure to delete after merging into main
- DO NOT UPLOAD ANY EXECUTABLE FILES. (I WILL TILT OFF THIS PLANET INTO OBLIVION)

## Compiling Code
I've made a very simple makefile for us to ease up compilation typing time.
ASSUMING you're using a linux like environment simple type to compile the program.
```
make
```
In order to remove the executable generated (must do before any commits or pushes or simply put in it in a gitignore file)
```
make clean
```

## Assignment02 status: DONE
#### TASKS
- [x] Add requested reserved words
- [x] Add requested special symbols
- [x] Add requested misc tokens (IDENTIFIER STRING ERROR etc)
- [x] Appropriately ignore comments
- [x] show proper line errors for the respective token error
- [x] run ScannerTest.txt and verify output

## Assignment03 status: PENDING
#### TASKS
- [x] Add WHILE to parser
- [ ] Add IF to parser
- [x] Add FOR to parser
- [ ] Add CASE to parser
- [ ] Implement the simple executor for above functionalities
- [X] Add WHILE executor
