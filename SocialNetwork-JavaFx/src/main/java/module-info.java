module com.example.javafxrezerva {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;


    opens com.example.javafxrezerva to javafx.fxml;
    opens social_network.domain to javafx.base;
    exports com.example.javafxrezerva;
}