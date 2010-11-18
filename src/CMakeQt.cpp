#include "CMakeQt.h"
#include "config.h" // Get all the 'params' from generated config.h from here

CMakeQt::CMakeQt(QWidget *parent)
    : QDialog(parent)
{
    m_ui.setupUi(this);

    m_ui.label->setText( m_ui.label->text().arg( PROJECT_COPYRIGHT, PROJECT_CONTACT,
                    ORG_WEBSITE, HOSTNAME, SYSNAME, PROJECT_VERSION, CODENAME ) );

    m_ui.trlabel->setText( tr("This is some text in English language.") );
}
