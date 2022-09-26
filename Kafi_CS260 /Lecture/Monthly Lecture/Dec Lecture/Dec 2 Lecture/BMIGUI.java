
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.*;
import java.awt.event.*;

public class BMIGUI implements ActionListener{
	
	JTextField heightField, weightField;
	JButton computeButton;
	JFrame frame; 
	JLabel bmiLabel;
	public BMIGUI(){
		// set up components
		heightField = new JTextField(5); 
		weightField = new JTextField(5); 
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
	
		// read height and weight info from text fields 
		String heightText = heightField.getText(); 
		double height = Double.parseDouble(heightText); 
		String weightText = weightField.getText(); 
		double weight = Double.parseDouble(weightText);
		
		// compute BMI and display it onscreen
		double bmi = weight / (height * height) * 703; 
		bmiLabel.setText(" BMI: " + bmi);
	
	}

	public static void main(String[] args) {

		BMIGUI gWindow = new BMIGUI();
	}

}
	