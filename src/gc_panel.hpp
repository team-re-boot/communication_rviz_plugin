#include "rviz_common/panel.hpp"
#include "rviz_common/display_context.hpp"
#include "communication_interfaces/msg/game_control_data.hpp"
#include <QBoxLayout>
#include <QLabel>

namespace communication_rviz_plugin
{
class GameControlDataPanel : public rviz_common::Panel
{
  Q_OBJECT

public:
  explicit GameControlDataPanel(QWidget * parent = 0);
  void onInitialize() override;

signals:
  void stamp(QString stamp);
  void packetnum(QString packetnum);
  void gameType(QString game_type);
  void state(QString state);
  void secondaryState(QString secondaryState);
  void secsRemaining(QString secs_remaining);
  void secondaryTime(QString secondary_time);
  void score(QString score);
  void teamName1(QString team_name_1);
  void teamName2(QString team_name_2);
  void pena101(QString pena101);
  void pena102(QString pena101);
  void pena103(QString pena101);
  void pena104(QString pena101);
  void pena105(QString pena101);
  void pena106(QString pena101);
  void pena201(QString pena101);
  void pena202(QString pena101);
  void pena203(QString pena101);
  void pena204(QString pena101);
  void pena205(QString pena101);
  void pena206(QString pena101);
  void ptime101(QString ptime101);
  void ptime102(QString ptime101);
  void ptime103(QString ptime101);
  void ptime104(QString ptime101);
  void ptime105(QString ptime101);
  void ptime106(QString ptime101);
  void ptime201(QString ptime101);
  void ptime202(QString ptime101);
  void ptime203(QString ptime101);
  void ptime204(QString ptime101);
  void ptime205(QString ptime101);
  void ptime206(QString ptime101);
  void pgk101(QString ptime101);
  void pgk102(QString ptime101);
  void pgk103(QString ptime101);
  void pgk104(QString ptime101);
  void pgk105(QString ptime101);
  void pgk106(QString ptime101);
  void pgk201(QString ptime101);
  void pgk202(QString ptime101);
  void pgk203(QString ptime101);
  void pgk204(QString ptime101);
  void pgk205(QString ptime101);
  void pgk206(QString ptime101);
  void pr101(QString pr101);
  void pr102(QString pr102);
  void pr103(QString pr103);
  void pr104(QString pr104);
  void pr105(QString pr105);
  void pr106(QString pr106);
  void pr201(QString pr201);
  void pr202(QString pr202);
  void pr203(QString pr203);
  void pr204(QString pr204);
  void pr205(QString pr205);
  void pr206(QString pr206);
  void py101(QString py101);
  void py102(QString py102);
  void py103(QString py103);
  void py104(QString py104);
  void py105(QString py105);
  void py106(QString py106);
  void py201(QString py201);
  void py202(QString py202);
  void py203(QString py203);
  void py204(QString py204);
  void py205(QString py205);
  void py206(QString py206);
  void pb101(QString pb101);
  void pb102(QString pb102);
  void pb103(QString pb103);
  void pb104(QString pb104);
  void pb105(QString pb105);
  void pb106(QString pb106);
  void pb201(QString pb201);
  void pb202(QString pb202);
  void pb203(QString pb203);
  void pb204(QString pb204);
  void pb205(QString pb205);
  void pb206(QString pb206);

private:
  rclcpp::Node::SharedPtr node_;
  rclcpp::Subscription<communication_interfaces::msg::GameControlData>::SharedPtr sub_;

  void connectSignalSlot();
  void emitSignals(communication_interfaces::msg::GameControlData const msg);
  QString penalties(uint8_t penalty);
  QString time(int16_t sec);
};
}  // namespace communication_rviz_plugin
