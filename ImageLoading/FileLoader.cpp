
#include "FileLoader.h"

void FileLoader::load_image() {
    string zenCmd = "zenity --file-selection --title=\"Select a File\"";
    string output = getCmdOutput(zenCmd);
    cout<<output[output.size()-2]<<endl;
    if (output[output.size()-2] == 'g'){
        output.pop_back();
        this->image = output;
    }
    else{
        error();
    }
}

void FileLoader::error() {
    string zenCmd = "zenity --info --title=\"Error Loading Image\" --text=\"Imagen no pudo ser cargada!\"";
    string output = getCmdOutput(zenCmd);
}

void FileLoader::getimagedivisions() {
    string zenCmd = "zenity --entry --title \"Entry of a value (4-20)\" --text \"Enter a value\"";
    string output = getCmdOutput(zenCmd);
    this->divisions = stoi(output);
}


string FileLoader::getCmdOutput(string cmd) {
    // string to store the final results in
    string outputString;

    // stream to capture the command output
    FILE *outpStream;

    // maximum line length when capturing
    //    command output
    const int MaxLineLen = 128;

    // storage for one line of captured output
    char  outpLine[MaxLineLen];

    // redirect the standard output from the command
    cmd += " 2>&1";

    // run the command, piping the output to our stream
    outpStream = popen(cmd.c_str(), "r");
    if (outpStream) {
        // capture the output, one line at a time,
        //    appending it to our output string
        while (!feof(outpStream)) {
            if (fgets(outpLine, MaxLineLen, outpStream) != NULL) {
                outputString += outpLine;
            }
        }
        pclose(outpStream);
    }
    return outputString;
}