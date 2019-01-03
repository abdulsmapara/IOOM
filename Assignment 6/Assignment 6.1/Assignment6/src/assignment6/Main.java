package assignment6;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/**
 *
 * @author abdulsmapara
 */
class Student{
    private String name;
    private int marks;
    Student(){
        name = null;
        marks = 0;
    }
    Student(String name,int marks){
        this.name = name;
        this.marks = marks;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getMarks() {
        return marks;
    }

    public void setMarks(int marks) {
        this.marks = marks;
    }
    
}
class NameComp implements Comparator<Student>{

    @Override
    public int compare(Student t, Student t1) {
       return t.getName().compareTo(t1.getName());
    }
    
}
class DecMarksComp implements Comparator<Student>{

    @Override
    public int compare(Student t, Student t1){
        int ret = 0;
        if(t1.getMarks() != t.getMarks()){
            ret = t1.getMarks()-t.getMarks();
        }else{
            ret = t.getName().compareTo(t1.getName());
        }
        return ret;        
    }
    
}
class IncMarksComp implements Comparator<Student>{

    @Override
    public int compare(Student t, Student t1) {
        int ret = 0;
        if(t.getMarks() != t1.getMarks())
            ret = t.getMarks() - t1.getMarks();
        else
            ret = t.getName().compareTo(t1.getName());
        return ret;
        
    }
    
}
class Task{
    private String output_file;
    Task(String output_file_path){
        output_file = output_file_path;
    }
    public void doTask(String file_path) throws FileNotFoundException,IOException{
        try{
            BufferedReader reader = new BufferedReader(new FileReader(file_path));
            Scanner sc = new Scanner(System.in);
            ArrayList<Student> arr = new ArrayList<>();
            String curr_line = reader.readLine();
            while(curr_line != null)
            {
                String[] str_arr = curr_line.split(" ");
                try{
                    arr.add(new Student(str_arr[0],Integer.parseInt(str_arr[1])));
                }catch(NumberFormatException e){
                    System.out.println("NumberFormatException " + e);
                }
                curr_line = reader.readLine();
            }
            reader.close();
            System.out.println("Options" + "\n" + "1] Sort Based on Name \n" + "2] Sort Based on Marks");
            int choice = sc.nextInt();
            while(choice < 1 || choice > 2){
                System.out.println("Enter a valid choice\n");
                choice = sc.nextInt();
            }
            switch(choice){
                case 1:
                    Collections.sort(arr, new NameComp());
                    break;
                case 2:
                    Collections.sort(arr, new DecMarksComp());  //------Decreasing order of marks------------if same marks--lexicographical sorting on names
                    break;
            }
            BufferedWriter writer = new BufferedWriter(new FileWriter(output_file));
            for(Student s : arr)
            {
                System.out.println(s.getName() + " " + s.getMarks());
                writer.write(s.getName());
                writer.write(" ");
                writer.write(String.valueOf(s.getMarks()));
                writer.newLine();
            }
            writer.close();
            
        }catch(FileNotFoundException e){
            System.out.println("File Not Found Exception "+e);
            throw new FileNotFoundException();
        }
    }
    String getOutputFile(){
        return output_file;
    }
}
public class Main {

    public static void main(String[] args) {
        Task task = new Task("/media/abdulsmapara/New Volume/IOOM/Assignment 6.1/Assignment6/src/assignment6/" + "output.txt");
        String file_path;
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter input file name");
        file_path = sc.nextLine();
        try{
            task.doTask(file_path);
            System.out.println("Output file: " + task.getOutputFile());
        }catch(FileNotFoundException e){
            System.out.println("FileNotFoundException " + e);
        }catch(IOException e){
            System.out.println("IOException " + e);
        }
    }
    
}
