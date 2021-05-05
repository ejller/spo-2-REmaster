const {getMode, getFilePath, getCommand} = require('./input.js');
const addon = require('./build/Release/lab2');

const parseValidArgs = (value, argsCount) => value.args.length === argsCount

const parseCommand = (fileSystem, value) => {
    if (parseValidArgs(value, 0) && value.command === 'exit') {
        return false
    } else if (parseValidArgs(value, 1) && value.command === 'cd') {
        // console.log(library.cd(fileSystem, value.args[0]))
    } else if (parseValidArgs(value, 0) && value.command === 'pwd') {
        // console.log(addon.pwd())
    } else if (parseValidArgs(value, 0) && value.command === 'ls') {
        // console.log(addon.pwd())
    } else if (parseValidArgs(value, 0) && value.command === 'help') {
        console.log("cd [path] - change working directory");
        console.log("cp [input path] [output path] - copy");
        console.log("ls - show current directory elements");
        console.log("pwd - print current directory");
        console.log("exit - stop program");
        console.log("help - print help");
    } else if (parseValidArgs(value, 2) && value.command === 'cp') {
        // console.log(library.cp(fileSystem, value.args[0], value.args[1]))
    } else {
        console.log("Invalid command. Enter help")
    }
    return true
}

const main = () => {
    const mode = getMode()
    if (mode === 1) {
        console.log(addon.first_mode());
    } else {
        const path = getFilePath();
        const fileSystem = addon.open_file_system(path)
        if(fileSystem==0){
            let run = true
            while (run) {
                const value = getCommand();
                run = parseCommand(fileSystem, value)
            }
            // addon.close_file_system()
        } else {
            console.log('Invalid path')
        }
    }
}

main()