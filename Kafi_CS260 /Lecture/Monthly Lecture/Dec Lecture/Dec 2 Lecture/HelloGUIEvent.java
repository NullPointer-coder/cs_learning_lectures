
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.*;
import java.awt.event.*;

public class HelloGUIEvent implements ActionListener{
	
	JTextField helloField;
	JButton computeButton;
	JFrame frame; 
	JLabel messageLabel;
	
	public HelloGUIEvent(){
		// set up components
		helloField = new JTextField(15); 
		
		messageLabel = new JLabel( "  Type your name  "); 
		computeButton = new JButton("Say Hello");
		computeButton.addActionListener(this);
		
		// layout 
		JPanel north = new JPanel(new GridLayout(1, 1)); 
		north.add(new JLabel(" Name: ")); 
		north.add(helloField);
		// overall frame 
		frame = new JFrame("Say Hello"); 
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
		frame.setLayout(new BorderLayout()); 
		frame.add(north, BorderLayout.NORTH); 
		frame.add(messageLabel, BorderLayout.CENTER); 
		frame.add(computeButton, BorderLayout.SOUTH); 
		frame.pack(); 
		frame.setVisible(true);
		
	}
	
	
	// Handles clicks on say hello button
	public void actionPerformed(ActionEvent event) {
	// read the name
	String nameText = helloField.getText(); 
	messageLabel.setText("  Hello: " + nameText);
	}

	public static void main(String[] args) {

		HelloGUIEvent gWindow = new HelloGUIEvent();
	}

}
	