#include "handlelocation.h"
#include "ui_handlelocation.h"

HandleLocation::HandleLocation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HandleLocation),
    m_view(new QWebEngineView(this))
{
    ui->setupUi(this);
    // Create a new vertical layout
    QVBoxLayout *layout = new QVBoxLayout;

    // Add the back button to the layout
    QPushButton *backButton = new QPushButton("Geri Dön", this);
                              layout->addWidget(backButton);

    connect(backButton, &QPushButton::clicked, this, &HandleLocation::on_backButton_clicked);

    layout->addWidget(m_view);


    QWidget *centralWidget = new QWidget(this);


    centralWidget->setLayout(layout);


    setCentralWidget(centralWidget);

    QWebEnginePage *page = m_view->page();

    connect(page, &QWebEnginePage::featurePermissionRequested,
            [this, page](const QUrl &securityOrigin, QWebEnginePage::Feature feature) {
                if (feature != QWebEnginePage::Geolocation)
                    return;
                QMessageBox msgBox(this);
                msgBox.setText(tr("%1 wants to know your location").arg(securityOrigin.host()));
                msgBox.setInformativeText(tr("Do you want to send your current location to this website?"));
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::Yes);

                if (msgBox.exec() == QMessageBox::Yes) {
                    page->setFeaturePermission(
                        securityOrigin, feature, QWebEnginePage::PermissionGrantedByUser);
                } else {
                    page->setFeaturePermission(
                        securityOrigin, feature, QWebEnginePage::PermissionDeniedByUser);
                }
            });
    //    page->load(QUrl(QStringLiteral("https://maps.google.com")));

    page->setHtml(R"(
    <!DOCTYPE html>
    <html>
    <body>
    <div id="map" style="width:100%;height:720px"></div>

    <script>
    function myMap() {
        var mapOptions = {
            center: new google.maps.LatLng(41.028327, 28.889866),
            zoom: 10,
        }
        var map = new google.maps.Map(document.getElementById("map"), mapOptions);

        var points = [
            {lat: 41.016921, lng: 28.910571, name: 'Cevizlibağ İspark'},
            {lat: 41.028912, lng: 28.888986, name: 'YTÜ Davutpaşa EEF Otopark'},
            {lat: 41.051823, lng: 29.010749, name: 'Ytü Yıldız Kampüsü Otopark'},
            // Add more points here
        ];

        points.forEach(function(point) {
            var marker = new google.maps.Marker({
                position: new google.maps.LatLng(point.lat, point.lng),
                map: map,
                title: point.name
            });

            marker.addListener('click', function() {
                var dialogBox = document.createElement('div');
                dialogBox.style.width = '200px';
                dialogBox.style.height = '100px';
                dialogBox.style.background = '#fff';
                dialogBox.style.position = 'fixed';
                dialogBox.style.top = '50%';
                dialogBox.style.left = '50%';
                dialogBox.style.transform = 'translate(-50%, -50%)';
                dialogBox.style.padding = '20px';
                dialogBox.style.boxShadow = '0px 0px 10px rgba(0,0,0,0.1)';
                dialogBox.innerHTML = "<p>Otopark Noktası: " + point.name + "</p><button onclick='this.parentNode.remove()'>Evet</button><button onclick='this.parentNode.remove()'>Hayır</button>";
                document.body.appendChild(dialogBox);
            });
        });

        // Kullanıcının konumunu al ve haritaya ekleyerek işaretle
        if (navigator.geolocation) {
            navigator.geolocation.getCurrentPosition(function(position) {
                var userMarker = new google.maps.Marker({
                    position: new google.maps.LatLng(position.coords.latitude, position.coords.longitude),
                    map: map,
                    title: 'Your Location',
                    icon: 'http://maps.google.com/mapfiles/ms/icons/blue-dot.png'  // İsterseniz özel bir ikon kullanabilirsiniz
                });
            });
        }
    }
    </script>

    <script src="https://maps.googleapis.com/maps/api/js?key=YOUR_OWN_API_KEY&callback=myMap"></script>
    </body>
    </html>
)");


}

HandleLocation::~HandleLocation()
{
    delete ui;
}

void HandleLocation::on_backButton_clicked()
{
    this->hide();  // Hide the login page
    if (parentWidget()) {
        parentWidget()->show();  // Show the parent widget (OpenPage)
    }

}


