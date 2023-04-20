package com.example.javafxrezerva;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import social_network.exceptions.ValidationException;
import social_network.service.UserService;

import java.io.IOException;

public class SignUpController {
    UserService srv;
    @FXML
    private TextField signUpEmail;
    @FXML
    private TextField signUpFirstName;
    @FXML
    private TextField signUpLastName;
    @FXML
    private TextField signUpId;
    @FXML
    private Label eroare;

    public void setSignUpService(UserService service) {
        this.srv = service;
    }

    public void logIn() throws IOException {
        Main main = new Main();
        main.switchToLogIn("login.fxml");
    }

    public void signUp() throws IOException {
        String email = signUpEmail.getText();
        String first_name = signUpFirstName.getText();
        String last_name = signUpLastName.getText();

        if (email.isEmpty() || first_name.isEmpty() || last_name.isEmpty()) {
            eroare.setText("Date invalide");
            eroare.setVisible(true);
        }
        Long id = Long.parseLong(signUpId.getText());
        if (srv.searchUtilizator_id(id) != null) {
            eroare.setText("Date invalide");
            eroare.setVisible(true);
        } else {
            try {
                //!!!!!!!!!!!!!!!!!!!!
                srv.addUserID(id, email, first_name, last_name);
                Main main = new Main();
                main.switchToLogIn("login.fxml");
            } catch (ValidationException e) {
                eroare.setText("Date invalide");
                eroare.setVisible(true);
            }
        }
    }
}


