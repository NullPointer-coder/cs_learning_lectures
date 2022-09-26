
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.KeyboardFocusManager;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.*;
import java.awt.event.*;

public class BMIEvents implements ActionListener{
	
	JTextField heightField, weightField;
	JButton computeButton;
	JFrame frame; 
	JLabel bmiLabel;
public BMIEvents(){
	// set up components
	heightField = new JTextField(5); 
	heightField.addActionListener(this);
	weightField = new JTextField(5); 
	weightField.addActionListener(this);
	bmiLabel = new JLabel( "  Type your height and weight  "); 
	computeButton = new JButton("Compute");
	computeButton.addActionListener(this);
	
	// layout 
	JPanel north = new JPanel(new GridLayout(2, 2)); 
	north.add(new JLabel(" Height: ")); 
	north.add(heightField); 
	north.add(new JLabel(" Weight: ")); 
	north.add(weightField); 
	
	// overall frame 
	frame = new JFrame("BMI"); 
	
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
	frame.setLayout(new BorderLayout()); 
	frame.add(north, BorderLayout.NORTH); 
	frame.add(bmiLabel, BorderLayout.CENTER); 
	frame.add(computeButton, BorderLayout.SOUTH); 
	frame.pack(); 
	frame.setVisible(true);
}
	 
	
// Handles clicks on Compute button by computing the BMI. 
public void actionPerformed(ActionEvent event) {
KeyboardFocusManager keyManager = KeyboardFocusManager.getCurrentKeyboardFocusManager();

if(event.getSource().equals(computeButton))
{	// read height and weight info from text fields
	double height = Double.parseDouble(heightField.getText()); 
	double weight = Double.parseDouble(weightField.getText());
	// compute BMI and display it onscreen
	double bmi = weight / (height * height) * 703; 
	bmiLabel.setText(" BMI: " + bmi);
	// move focus back to heightField
	keyManager.focusNextComponent();
}
// enter event
else if (event.getSource().equals(heightField)){
	try{	
		Double.parseDouble(heightField.getText());
		// move focus to weightField
		keyManager.focusNextComponent();
	}
	catch(Exception e){
		heightField.setText(""); // error: clear text
	}
	
}
else if (event.getSource().equals(weightField)){
	try{
		Double.parseDouble(weightField.getText());
		// move focus back to computeButton
		keyManager.focusNextComponent();
	}
	catch(Exception e){
		weightField.setText(""); // error: clear text
	}
}
}

	public static void main(String[] args) {
		BMIEvents gWindow = new BMIEvents();
	}

}
	