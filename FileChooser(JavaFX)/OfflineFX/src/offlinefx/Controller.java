/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sample;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.ResourceBundle;
import java.util.Scanner;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;

import javafx.stage.FileChooser;

/**
 *
 * @author Lenovo
 */
public class Controller implements Initializable {

    @FXML
    private Button btn;
     @FXML
    private Button btn2;
    @FXML private Label label;
    @FXML private Label label2;
    @FXML private ListView<String>words;
    @FXML private ListView<String>frequency;

    @FXML private final ObservableList<String>data=FXCollections.observableArrayList();

   
    
       
       @FXML
      private File file;
    //String[] fr;




    @FXML
    private void click(ActionEvent event) throws FileNotFoundException {


        FileChooser fc= new FileChooser();
       

        fc.getExtensionFilters().addAll(new FileChooser.ExtensionFilter("Text Files","*.txt"));

         file= fc.showOpenDialog(null);
      
    }
    @FXML
    public void press(ActionEvent e) throws FileNotFoundException
    {
         int i=0,count,j,k;
         words.getItems().clear();
          frequency.getItems().clear();
           File fo=new File(file.getAbsolutePath());
       
        String[] st=new String[1000];
        
            Scanner input=new Scanner(fo);
        input= input.useDelimiter("[^A-Za-z0-9]+");

        while(input.hasNext())
        {

            st[i]=input.next();
            System.out.println(st[i]);
            i++;

        }
        for(j=0;st[j]!=null;j++)
        {
            count=1;
            
                for( k=j+1;st[k]!=null;k++)
                {
                    if(st[j].equalsIgnoreCase(st[k]))
                       
                    {
                        List<String>list=new ArrayList<String>(Arrays.asList(st));
                        list.remove(k);
                        st=list.toArray(new String[0]);
                        count++;

                    }


                }
          
           
            words.getItems().addAll(st[j]);
            frequency.getItems().addAll(String.valueOf(count));
                   System.out.println(st[j]);
            System.out.println(count);
            
           


        }

    }


    @Override
    public void initialize(URL url, ResourceBundle rb) {


    }
}
