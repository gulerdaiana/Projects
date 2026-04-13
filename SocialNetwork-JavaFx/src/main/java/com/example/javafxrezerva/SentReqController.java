package com.example.javafxrezerva;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import social_network.Observer.Observer;
import social_network.domain.User;
import social_network.domain.UserDTOFriend;
import social_network.service.AppService;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class SentReqController implements Observer {

    private ObservableList<User> usersList = FXCollections.observableArrayList();
    private ObservableList<UserDTOFriend> friendList = FXCollections.observableArrayList();
    private ObservableList<User> friendRequestsList = FXCollections.observableArrayList();
    public ObservableList<User> sentRequestsList = FXCollections.observableArrayList();
    private AppService service;
    private User loggedUser = null;
    @FXML
    public Button deleteSentRequestButton;
    @FXML
    public TableView<User> sentRequestsTableView;
    @FXML
    public TableColumn<User, String> sentRequestsFirst_nameColumn;
    @FXML
    public TableColumn<User, String> sentRequestsLast_nameColumn;
    @FXML
    public TableColumn<User, String> sentRequestsEmailColumn;

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

        List<User> sentRequests = new ArrayList<>();
        List<User> friendRequests = service.getSentRequests(loggedUser.getId());
        for (User user : friendReqOfUsers) {
            sentRequests.add(user);
        }

        sentRequestsList.setAll(friendRequests);

    }

    @Override
    public void update() {
        initLists();
    }

    @FXML
    public void initialize() {
        sentRequestsFirst_nameColumn.setCellValueFactory(new PropertyValueFactory<User, String>("first_name"));
        sentRequestsLast_nameColumn.setCellValueFactory(new PropertyValueFactory<User, String>("last_name"));
        sentRequestsEmailColumn.setCellValueFactory(new PropertyValueFactory<User, String>("email"));

        sentRequestsTableView.setItems(sentRequestsList);
    }

    public void onRemoveSendRequestButton() {

        try {
            long friendID = sentRequestsTableView.getSelectionModel().getSelectedItem().getId();
            service.removeFriendship(friendID, loggedUser.getId());
        } catch (NullPointerException npe) {
            Alert alert = new Alert(Alert.AlertType.WARNING, "No friend selected!", ButtonType.OK);
            alert.show();
        } catch (Exception ex) {
            ex.printStackTrace();
            Alert alert = new Alert(Alert.AlertType.ERROR, ex.getMessage(), ButtonType.OK);
            alert.show();
        }
    }

    public void onbackSentRequests() throws IOException {
        Main main = new Main();
        main.switchToMain("main_.fxml", loggedUser.getEmail());
    }
}
