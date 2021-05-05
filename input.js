import readlineSync from 'readline-sync';

export const getMode = () => {
    let mode = 0;
    while (mode === 0) {
        const input = parseInt(readlineSync.question('Select the mod in which the program will run (1/2): '));
        if (input === 1 || input === 2) {
            mode = input
        } else {
            console.log('Enter the correct mod number')
        }
    }
    return mode;
}

export const getFilePath = () => readlineSync.question('Enter path: ')

export const getCommand = () => {
    const input = readlineSync.question('> ')
    const tmp = input.split(' ')
    if (tmp.length > 4) console.log('Invalid args')
    const command = tmp[0]
    tmp.shift()
    return {
        command,
        args: tmp,
    }
}