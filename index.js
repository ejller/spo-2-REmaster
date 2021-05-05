import {getMode, getFilePath, getCommand} from './input.js';
import addon from './build/Release/lab2.node';

const main = () => {
    const mode = getMode()
    if (mode === 1) {
        addon.my_function1(8)
        // library.first_mode();
    } else {
        // const path = getFilePath();
        // const fileSystem = library.openFileSystem(path)
        // if (fileSystem.hexAddress() != '(nil)') {
        //     let run = true
        //     while (run) {
        //         const value = getCommand();
        //         run = parseCommand(fileSystem, value)
        //     }
        //     library.closeFileSystem(fileSystem)
        // } else {
        //     console.log('Invalid path')
        // }
    }
}

main()