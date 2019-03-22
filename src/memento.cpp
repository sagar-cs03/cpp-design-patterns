#include <bits/stdc++.h>
using namespace std;


class Editor {

    private:
    string txt;
    int cordX, cordY;

    public:
    
    class Snapshot {
        private:
        //Note that in java implementation, you wouldn't require the reference to the enclosing class, as 
        //the outer class can directly access the inner class private methods. This is not allowed in C++, hence the below field
        Editor* editor;
        string txt;
        int cordX, cordY;

        public:
        Snapshot(Editor* editor, string txt, int cordX, int cordY) {
            this->editor = editor;
            this->txt = txt;
            this->cordX = cordX;
            this->cordY = cordY;
        } 

        void RestoreState() {
            this->editor->txt = txt;
            this->editor->cordX = cordX;
            this->editor->cordY = cordY;
        }

    };
    
    
    Editor(string txt, int cordX, int cordY) {
        this->txt = txt;
        this->cordX = cordX;
        this->cordY = cordY;
    }

    void ChangeText(string txt) {
        this->txt = txt;
        this->cordX = this->cordX + 5;
        this->cordY = this->cordY + 1;
    }


    void PrintEditorContents() {
        cout << txt << " " << endl;
    }
 

    Snapshot* MakeBackUp() {
        return new Snapshot(this, txt, cordX, cordY);
    }


};


class CareTaker {
    private:
    
    Editor* editor;
    public:
    Editor::Snapshot* lastCommand;

    CareTaker(Editor* editor) {
        this->editor = editor;
    }

    void AddTextCommand(string txt) {
        lastCommand =  editor->MakeBackUp();
        editor->ChangeText(txt);
    }

    void UndoLastCommand() {
        if (lastCommand != NULL) {
            lastCommand->RestoreState();
            lastCommand = NULL;
        } else {
            cout << "Perform some changes in the editor, then try again" << endl;
            cout << "Note that you can only go back one step back " << endl;
        }
    };

};

int main () {
    Editor editor("This is version 1", 5, 10);
    CareTaker historyCareTaker(&editor);
    historyCareTaker.AddTextCommand("This is version 2");
    historyCareTaker.AddTextCommand("This is version 3");

    //prints -- this is version 3
    editor.PrintEditorContents();

    //undoes the last command which added "this is version 3"
    historyCareTaker.UndoLastCommand();

    //prints -- this is version 2
    editor.PrintEditorContents();

    //this undo doesn't change any state - as you are already one step back
    historyCareTaker.UndoLastCommand();

    //prints the last editor state as is
    editor.PrintEditorContents();
    return 0;
}