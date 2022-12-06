package code6_1001937588;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;

public class Password extends JFrame 
{
    private final JPasswordField passwordfield;
    private String user_pasword;
    private final String realpassword = "5253";

    public Password() 
    {
        super("Enter The Password to continue");
        setLayout(new FlowLayout());
        passwordfield = new JPasswordField(10);
        passwordfield.selectAll();
        passwordfield.setEchoChar('X');
        add(passwordfield);
        EventHandler handler = new EventHandler();
        passwordfield.addActionListener(handler);

    }

    private class EventHandler implements ActionListener 
    {
        @Override
        public void actionPerformed(ActionEvent event) 
        {
            
            String string = "";

            if (event.getSource() == passwordfield) 
            {
                user_pasword = event.getActionCommand();
            }
            if(user_pasword.equals(realpassword))
            {
                setVisible(false);
                GameFrame gameFrame = new GameFrame();
                gameFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                gameFrame.setSize(780,780);
                gameFrame.setVisible(true);
            }
            else
            {
                JOptionPane.showMessageDialog(null, "Invalid Password...please try again");
            }
            
        }

    }

}
