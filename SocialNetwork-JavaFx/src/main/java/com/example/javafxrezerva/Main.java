package com.example.javafxrezerva;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import social_network.Validators.FriendshipValidator;
import social_network.Validators.UserValidator;
import social_network.domain.User;
import social_network.repository.database.DBFriendshipRepo;
import social_network.repository.database.DBMessageRepo;
import social_network.repository.database.DBUserRepo;
import social_network.service.AppService;
import social_network.service.FriendshipService;
import social_network.service.UserService;

import java.io.IOException;


public class Main extends Application {

    String url = "jdbc:postgresql://localhost:5432/social_network";
    String username = "postgres";
    String password = "password";

    DBUserRepo repoUser = new DBUserRepo(url, username, password);
    FriendshipValidator frval = new FriendshipValidator();
    UserValidator userval = new UserValidator();
    DBFriendshipRepo repoFriendship = new DBFriendshipRepo(url, username, password);

    FriendshipService friendshipService = new FriendshipService(repoFriendship, repoUser);
    UserService userService = new UserService(repoUser, repoFriendship);
    DBMessageRepo repoMessage = new DBMessageRepo(url, username, password);

    AppService mainservice = new AppService(repoUser, repoFriendship, userval, frval, repoMessage);


    private static Stage currentStage;

    @Override
    public void start(Stage stage) throws IOException {
        currentStage = stage;

        FXMLLoader loader = new FXMLLoader(Main.class.getResource("login.fxml"));
        AnchorPane root = loader.load();
        LogInController controller = loader.getController();
        controller.setLogInService(userService);
        Scene scene_new = new Scene(root, 559, 450);
        scene_new.setFill((Color.web("#81c483")));
        currentStage.setScene(scene_new);
        currentStage.setTitle("Log in");
        currentStage.show();
    }


    public void switchToLogIn(String fxml) throws IOException {
        FXMLLoader loader = new FXMLLoader(Main.class.getResource(fxml));
        AnchorPane root = loader.load();
        LogInController controller = loader.getController();
        controller.setLogInService(userService);
        Scene login_scene = new Scene(root, 559, 450);
        login_scene.setFill((Color.web("#81c483")));
        currentStage.setScene(login_scene);
        currentStage.setTitle("Log in");
        currentStage.show();
    }

    public void switchToSignUp(String fxml) throws IOException {
        FXMLLoader loader = new FXMLLoader(Main.class.getResource(fxml));
        AnchorPane root = loader.load();
        SignUpController controller = loader.getController();
        controller.setSignUpService(userService);
        currentStage.setScene(new Scene(root, 474, 500));
        currentStage.setTitle("Sign up");
        currentStage.show();
    }


    public void switchToMain(String fxml, String email) throws IOException {
        FXMLLoader loader = new FXMLLoader(Main.class.getResource(fxml));
        AnchorPane root = loader.load();
        MainController controller = loader.getController();
        controller.setService(mainservice, email);
        currentStage.setScene(new Scene(root, 900, 440));
        currentStage.centerOnScreen();
        currentStage.setTitle("Main page");
        currentStage.show();
    }

    public void switchToChat(String fxml, User user) throws IOException {
        FXMLLoader loader = new FXMLLoader(Main.class.getResource(fxml));
        AnchorPane root = loader.load();
        MessageController controller = loader.getController();
        controller.setService(mainservice, user);
        currentStage.setScene(new Scene(root, 700, 500));
        currentStage.setTitle("Chat");
        currentStage.show();
    }

    public void switchToRequests(String fxml, User user) throws IOException {
        FXMLLoader loader = new FXMLLoader(Main.class.getResource(fxml));
        AnchorPane root = loader.load();
        RequestsController controller = loader.getController();
        controller.setService(mainservice, user);
        currentStage.setScene(new Scene(root, 550, 500));
        currentStage.setTitle("My Requests");
        currentStage.show();
    }

    public void switchToSentRequests(String fxml, User user) throws IOException {
        FXMLLoader loader = new FXMLLoader(Main.class.getResource(fxml));
        AnchorPane root = loader.load();
        SentReqController controller = loader.getController();
        controller.setService(mainservice, user);
        currentStage.setScene(new Scene(root, 550, 500));
        currentStage.setTitle("Sent Requests");
        currentStage.show();
    }


    public static void main(String[] args) {
        launch();
    }
}