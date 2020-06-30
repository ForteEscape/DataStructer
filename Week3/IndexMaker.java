package Week3;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class IndexMaker {
    
    static String[] words = new String[1000000];
    static int[] count = new int[1000000];
    static int size = 0;
    public static void main(String[] args){
        commandLine();
    }

    static void commandLine(){
        Scanner sc = new Scanner(System.in);

        System.out.println("$");
        String command = sc.next();

        while(true){
            if(command.equals("exit")){
                break;
            }
            else if(command.equals("Read")){
                readFile();
            }
            else if(command.equals("Find")){
                String keyWord = sc.next();
                printWordCount(keyWord);
            }
            else if(command.equals("SaveAs")){
                String fileName = sc.next();
                saveFiles(fileName);
            }
        }
        sc.close();
    }

    static void readFile(){
        Scanner inFile;
        try{
            String path = "C:\\Users\\sehunkim\\Desktop\\WorkSpace\\WorkSpace\\DataStructer\\Week3\\sample.txt";
            inFile = new Scanner(new File(path));

            while(inFile.hasNext()){
                String str = inFile.next();

                if(findWord(str) == 0){
                    words[size] = str;
                    size++;
                }
                else{
                    count[findWord(str)]++;
                }
            }
        }
        catch(FileNotFoundException e){
            System.out.println("File not found");
            return;
        }
    }

    static int findWord(String key){
        for(int i = 0; i<size; i++){
            if(words[i].equals(key)){ // if str is overlap in array members return index of overlap member
                return i;
            }
        }
        return 0;                     // if str is unique in arrays
    }

    static void printWordCount(String key){
        int result = 0;

        if(findWord(key) != 0){
            result = count[findWord(key)];
            System.out.println("Word "+key+"appears "+result+" times in this input data");
        }
        else{
            System.out.println("The Word "+key+"is not exsist in this input data");
        }
    }

    static void saveFiles(String fileName){
        try{
            PrintWriter out = new PrintWriter(new FileWriter(fileName));
            for(int i = 0; i<size; i++){
                out.println(words[i]+" "+count[i]);
            }
            out.close();
        }
        catch(IOException e){
            System.out.println("Saved failed");
        }
    }
}