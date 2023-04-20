package com.example.javafxrezerva;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.ListView;
import social_network.Observer.Observer;
import social_network.domain.User;
import social_network.domain.UserDTOFriend;
import social_network.service.AppService;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class RequestsController implements Observer {

    private ObservableList<User> usersList = FXCollections.observableArrayList();
    private ObservableList<UserDTOFriend> friendList = FXCollections.observableArrayList();
    private ObservableList<User> friendRequestsList = FXCollections.observableArrayList();
    public ObservableList<User> sentRequestsList = FXCollections.observableArrayList();
    private AppService service;
    private User loggedUser = null;
    @FXML
    public ListView<User> friendRequestsListView;
    @FXML
    public Button acceptButton;
    @FXML
    public Button rejectButton;


    public void setService(AppService service, User user) {
        this.service = service;
        this.service.addObserver(this);
        this.loggedUser = user;
        initLists();
    }

    private void initLists() {

        List<User> friendReqTemp = new ArrayList<>();
        List<User> friendReqOfUsers = service.getFriendRequests(loggedUser.getId());
        for (User user : friendReqOfUsers) {
            friendReqTemp.add(user);
        }
        friendRequestsList.setAll(friendReqTemp);

    }

    @FXML
    public void initialize() {
        friendRequestsListView.setItems(friendRequestsList);
        acceptButton.setStyle("-fx-background-color: #90EE90; ");
        rejectButton.setStyle("-fx-background-color: #FF0000; ");
        //initLists();

    }

    @Override
    public void update() {
        initLists();
    }


    @FXML
    public void onRejectFriendrequestButton() {
        try {
            Long userID = friendRequestsListView.getSelectionModel().getSelectedItem().getId();
            service.removeFriendship(userID, loggedUser.getId());
        } catch (NullPointerException npe) {
            Alert alert = new Alert(Alert.AlertType.WARNING, "No user selected!", ButtonType.OK);
            alert.show();
        } catch (Exception ex) {
            Alert alert = new Alert(Alert.AlertType.ERROR, ex.getMessage(), ButtonType.OK);
            alert.show();
        }
    }

    @FXML
    public void onacceptButton() {
        try {
            long id = friendRequestsListView.getSelectionModel().getSelectedItem().getId();
            service.addFriendship(loggedUser.getId(), id);

        } catch (NullPointerException npe) {
            Alert alert = new Alert(Alert.AlertType.WARNING, "No user selected!", ButtonType.OK);
            alert.show();
        } catch (Exception ex) {
            Alert alert = new Alert(Alert.AlertType.ERROR, ex.getMessage(), ButtonType.OK);
            alert.show();
        }
    }

    public void onbackFromRequests() throws IOException {
        Main main = new Main();
        main.switchToMain("main_.fxml", loggedUser.getEmail());
    }
}
