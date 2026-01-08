# CatchUp 

This is a learning project. I'll rewrite it in Rust in the future.
Using the SDL library.

### Rules of the game
The Wolf plays the role of the catcher, and the Hares running away from him.
The task of the Hares is to survive as long as possible or defeat the wolf with the help of a magic carrot that appears in a random place with a random cooldown. If the hare eats this carrot, he will become incredibly strong and will be able to defeat the wolf, but if he does not have time to reach the carrot, then the wolf has a chance to destroy it, which will increase his chances of winning.

### Environment:
Hares can use their environment to their advantage.
For example, to escape from a wolf being pursued, or if they are lucky, to eat a carrot that appears in the wolf’s out-of-sight area.

# Progress
- [x] Window created
- [x] The playing field has been created
- [ ] Implemented game objects (these are Wolf, Hare, Carrot)
- [ ] Add simple artificial intelligence
- [ ] Window with a message about the results of the round

# Building CatchUp

First, you should install CMake to build the project.

If you already have a folder named `~/build`, go to it within your project directory, and then enter the following command:
```sh
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
```

Open `CatchUp.sln` in the `~/build` folder.

There are difficulties: the dynamic library SDL3.dll is not copied to the executable file directory, which causes an error when starting.
