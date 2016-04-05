package com.nokia;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class JavaCount {

    private static BufferedReader reader;

    public ArrayList<File> listFiles(File path) {
        ArrayList<File> files = new ArrayList<File>();
        for (File file : path.listFiles()) {
            if (file.isDirectory() && !file.isHidden()) {
                files.addAll(listFiles(file));
            } else {
                if (file.getAbsolutePath().endsWith(".java")) {
                    files.add(file);
                }
            }
        }
        return files;
    }

    public int countFile(String filename) {
        int counter = 0;
        String line = null;
        try {
            reader = new BufferedReader(new InputStreamReader(
                    new FileInputStream(filename)));
            line = reader.readLine();
            while (null != line) {
                if (line.trim().length() != 0) {
                    counter++;
                }
                line = reader.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return counter;
    }

    public static void main(String[] args) {
        JavaCount test = new JavaCount();
        ArrayList<File> data = test.listFiles(new File(
                "D:\\gitdir\\Game\\Tetris\\src"));
        int sum = 0;
        for (File file : data) {
            int temp = test.countFile(file.toString());
            System.out.println(file.toString() + temp);
            sum += temp;
        }
        System.out.println(sum);
    }
}
