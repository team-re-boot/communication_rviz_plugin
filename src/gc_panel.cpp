#include "gc_panel.hpp"
#include <pluginlib/class_list_macros.hpp>
#include "qt/mywidget.h"

namespace communication_rviz_plugin
{
GameControlDataPanel::GameControlDataPanel(QWidget * parent)
: rviz_common::Panel(parent)
{
  auto widget = new MyWidget();
  auto layout = new QGridLayout();
  layout->addWidget(widget);
  setLayout(layout);
}

void GameControlDataPanel::onInitialize()
{
  connectSignalSlot();

  node_ = getDisplayContext()->getRosNodeAbstraction().lock()->get_raw_node();
  auto callback = [this](communication_interfaces::msg::GameControlData const msg) {
      this->emitSignals(msg);
    };
  sub_ = node_->create_subscription<communication_interfaces::msg::GameControlData>(
    "/game_controller_receiver/gc_data", rclcpp::QoS(10), callback);
}

void GameControlDataPanel::connectSignalSlot()
{
  std::function<QWidget * (std::string, QLayout *)> find_widget = //
    [&find_widget](std::string object_name, QLayout * layout) {
      for (int i = 0; i < layout->count(); ++i) {
        auto child = layout->itemAt(i);
        if (child->widget() != nullptr) {
          if (child->widget()->objectName().toStdString() == object_name) {
            return child->widget();
          } else if (child->widget()->layout() != nullptr) {
            auto candidate = find_widget(object_name, child->widget()->layout());
            if (candidate != nullptr) {
              return candidate;
            }
          }
        } else if (child->layout() != nullptr) {
          auto candidate = find_widget(object_name, child->layout());
          if (candidate != nullptr) {
            return candidate;
          }
        }
      }

      return (QWidget *) nullptr;
    };

  connect(
    this, SIGNAL(stamp(QString)), //
    find_widget("label_stamp", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(packetnum(QString)), //
    find_widget("label_packetnum", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(gameType(QString)), //
    find_widget("label_gt", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(state(QString)), //
    find_widget("label_gs", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(secondaryState(QString)), //
    find_widget("label_sgs", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(secsRemaining(QString)), //
    find_widget("label_time", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(secondaryTime(QString)), //
    find_widget("label_st", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(score(QString)), //
    find_widget("label_score", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(teamName1(QString)), //
    find_widget("label_tn1", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(teamName2(QString)), //
    find_widget("label_tn2", layout()), SLOT(setText(QString)));

  connect(
    this, SIGNAL(pena101(QString)), //
    find_widget("label_pena_101", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pena102(QString)), //
    find_widget("label_pena_102", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pena103(QString)), //
    find_widget("label_pena_103", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pena104(QString)), //
    find_widget("label_pena_104", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pena105(QString)), //
    find_widget("label_pena_105", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pena106(QString)), //
    find_widget("label_pena_106", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pena201(QString)), //
    find_widget("label_pena_201", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pena202(QString)), //
    find_widget("label_pena_202", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pena203(QString)), //
    find_widget("label_pena_203", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pena204(QString)), //
    find_widget("label_pena_204", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pena205(QString)), //
    find_widget("label_pena_205", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pena206(QString)), //
    find_widget("label_pena_206", layout()), SLOT(setText(QString)));

  connect(
    this, SIGNAL(ptime101(QString)), //
    find_widget("label_ptime_101", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(ptime102(QString)), //
    find_widget("label_ptime_102", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(ptime103(QString)), //
    find_widget("label_ptime_103", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(ptime104(QString)), //
    find_widget("label_ptime_104", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(ptime105(QString)), //
    find_widget("label_ptime_105", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(ptime106(QString)), //
    find_widget("label_ptime_106", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(ptime201(QString)), //
    find_widget("label_ptime_201", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(ptime202(QString)), //
    find_widget("label_ptime_202", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(ptime203(QString)), //
    find_widget("label_ptime_203", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(ptime204(QString)), //
    find_widget("label_ptime_204", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(ptime205(QString)), //
    find_widget("label_ptime_205", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(ptime206(QString)), //
    find_widget("label_ptime_206", layout()), SLOT(setText(QString)));

  connect(
    this, SIGNAL(pgk101(QString)), //
    find_widget("label_pgk_101", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pgk102(QString)), //
    find_widget("label_pgk_102", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pgk103(QString)), //
    find_widget("label_pgk_103", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pgk104(QString)), //
    find_widget("label_pgk_104", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pgk105(QString)), //
    find_widget("label_pgk_105", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pgk106(QString)), //
    find_widget("label_pgk_106", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pgk201(QString)), //
    find_widget("label_pgk_201", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pgk202(QString)), //
    find_widget("label_pgk_202", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pgk203(QString)), //
    find_widget("label_pgk_203", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pgk204(QString)), //
    find_widget("label_pgk_204", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pgk205(QString)), //
    find_widget("label_pgk_205", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pgk206(QString)), //
    find_widget("label_pgk_206", layout()), SLOT(setText(QString)));

  connect(
    this, SIGNAL(pr101(QString)), //
    find_widget("label_pr_101", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pr102(QString)), //
    find_widget("label_pr_102", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pr103(QString)), //
    find_widget("label_pr_103", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pr104(QString)), //
    find_widget("label_pr_104", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pr105(QString)), //
    find_widget("label_pr_105", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pr106(QString)), //
    find_widget("label_pr_106", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pr201(QString)), //
    find_widget("label_pr_201", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pr202(QString)), //
    find_widget("label_pr_202", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pr203(QString)), //
    find_widget("label_pr_203", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pr204(QString)), //
    find_widget("label_pr_204", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pr205(QString)), //
    find_widget("label_pr_205", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pr206(QString)), //
    find_widget("label_pr_206", layout()), SLOT(setText(QString)));

  connect(
    this, SIGNAL(py101(QString)), //
    find_widget("label_py_101", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(py102(QString)), //
    find_widget("label_py_102", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(py103(QString)), //
    find_widget("label_py_103", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(py104(QString)), //
    find_widget("label_py_104", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(py105(QString)), //
    find_widget("label_py_105", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(py106(QString)), //
    find_widget("label_py_106", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(py201(QString)), //
    find_widget("label_py_201", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(py202(QString)), //
    find_widget("label_py_202", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(py203(QString)), //
    find_widget("label_py_203", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(py204(QString)), //
    find_widget("label_py_204", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(py205(QString)), //
    find_widget("label_py_205", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(py206(QString)), //
    find_widget("label_py_206", layout()), SLOT(setText(QString)));

  connect(
    this, SIGNAL(pb101(QString)), //
    find_widget("label_pb_101", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pb102(QString)), //
    find_widget("label_pb_102", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pb103(QString)), //
    find_widget("label_pb_103", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pb104(QString)), //
    find_widget("label_pb_104", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pb105(QString)), //
    find_widget("label_pb_105", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pb106(QString)), //
    find_widget("label_pb_106", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pb201(QString)), //
    find_widget("label_pb_201", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pb202(QString)), //
    find_widget("label_pb_202", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pb203(QString)), //
    find_widget("label_pb_203", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pb204(QString)), //
    find_widget("label_pb_204", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pb205(QString)), //
    find_widget("label_pb_205", layout()), SLOT(setText(QString)));
  connect(
    this, SIGNAL(pb206(QString)), //
    find_widget("label_pb_206", layout()), SLOT(setText(QString)));
}

void GameControlDataPanel::emitSignals(communication_interfaces::msg::GameControlData const msg)
{
  emit stamp(QString::fromStdString(
      std::to_string(msg.std_header.stamp.sec) + "." + std::string(
        std::max(
          0, 9 - (int)(std::to_string(msg.std_header.stamp.nanosec)).size()),
        '0') + std::to_string(msg.std_header.stamp.nanosec))
  );

  emit packetnum(QString::fromStdString(
      "Packet num: " +
      std::string(
        std::max(0, 3 - (int)(std::to_string(msg.packet_number)).size()), '0') +     //
      std::to_string(msg.packet_number)));

  emit gameType(
    msg.game_type == 0 ? "round robin" :
    msg.game_type == 1 ? "playoff" :
    msg.game_type == 2 ? "drop-in" :
    "unknown");

  emit state(
    msg.state == 0 ? "Initial" :
    msg.state == 1 ? "Ready" :
    msg.state == 2 ? "set" :
    msg.state == 3 ? "Playing" :
    msg.state == 4 ? "Finished" :
    "unknown");

  emit secondaryState(
    msg.secondary_state == 0 ? "Normal" :
    msg.secondary_state == 1 ? "Penalty Shoot" :
    msg.secondary_state == 2 ? "Overtime" :
    msg.secondary_state == 3 ? "Timeout" :
    msg.secondary_state == 4 ? "Direct Free Kick" :
    msg.secondary_state == 5 ? "Indirect Free Kick" :
    msg.secondary_state == 6 ? "Penalty Kick" :
    msg.secondary_state == 7 ? "Corner Kick" :
    msg.secondary_state == 8 ? "Goal Kick" :
    msg.secondary_state == 9 ? "Throw-In" :
    "Unknown");

  emit secsRemaining(QString::fromStdString(
      std::string(
        std::max(0, 2 - (int)(std::to_string(msg.secs_remaining / 60)).size()),
        '0') + std::to_string(msg.secs_remaining / 60) + ":" +
      std::string(
        std::max(0, 2 - (int)(std::to_string(msg.secs_remaining % 60)).size()),
        '0') + std::to_string(msg.secs_remaining % 60)
  ));

  emit secondaryTime(QString::fromStdString(
      std::string(
        std::max(0, 2 - (int)(std::to_string(msg.secondary_time / 60)).size()),
        '0') + std::to_string(msg.secondary_time / 60) + ":" +
      std::string(
        std::max(0, 2 - (int)(std::to_string(msg.secondary_time % 60)).size()),
        '0') + std::to_string(msg.secondary_time % 60)
  ));

  emit score(QString::fromStdString(
      std::to_string(msg.teams[0].score) + " - " + std::to_string(msg.teams[1].score)));

  emit teamName1(QString::fromStdString(
      "Team ID: " +
      std::to_string(msg.teams[0].team_number)));

  emit teamName2(QString::fromStdString(
      "Team ID: " +
      std::to_string(msg.teams[1].team_number)));


  emit pena101(penalties(msg.teams[0].players[0].penalty));
  emit pena102(penalties(msg.teams[0].players[1].penalty));
  emit pena103(penalties(msg.teams[0].players[2].penalty));
  emit pena104(penalties(msg.teams[0].players[3].penalty));
  emit pena105(penalties(msg.teams[0].players[4].penalty));
  emit pena106(penalties(msg.teams[0].players[5].penalty));
  emit pena201(penalties(msg.teams[1].players[0].penalty));
  emit pena202(penalties(msg.teams[1].players[1].penalty));
  emit pena203(penalties(msg.teams[1].players[2].penalty));
  emit pena204(penalties(msg.teams[1].players[3].penalty));
  emit pena205(penalties(msg.teams[1].players[4].penalty));
  emit pena206(penalties(msg.teams[1].players[5].penalty));

  emit ptime101(time(msg.teams[0].players[0].secs_till_unpenalised));
  emit ptime102(time(msg.teams[0].players[1].secs_till_unpenalised));
  emit ptime103(time(msg.teams[0].players[2].secs_till_unpenalised));
  emit ptime104(time(msg.teams[0].players[3].secs_till_unpenalised));
  emit ptime105(time(msg.teams[0].players[4].secs_till_unpenalised));
  emit ptime106(time(msg.teams[0].players[5].secs_till_unpenalised));
  emit ptime201(time(msg.teams[1].players[0].secs_till_unpenalised));
  emit ptime202(time(msg.teams[1].players[1].secs_till_unpenalised));
  emit ptime203(time(msg.teams[1].players[2].secs_till_unpenalised));
  emit ptime204(time(msg.teams[1].players[3].secs_till_unpenalised));
  emit ptime205(time(msg.teams[1].players[4].secs_till_unpenalised));
  emit ptime206(time(msg.teams[1].players[5].secs_till_unpenalised));

  emit pgk101(msg.teams[0].players[0].goalkeeper ? "o" : "");
  emit pgk102(msg.teams[0].players[1].goalkeeper ? "o" : "");
  emit pgk103(msg.teams[0].players[2].goalkeeper ? "o" : "");
  emit pgk104(msg.teams[0].players[3].goalkeeper ? "o" : "");
  emit pgk105(msg.teams[0].players[4].goalkeeper ? "o" : "");
  emit pgk106(msg.teams[0].players[5].goalkeeper ? "o" : "");
  emit pgk201(msg.teams[1].players[0].goalkeeper ? "o" : "");
  emit pgk202(msg.teams[1].players[1].goalkeeper ? "o" : "");
  emit pgk203(msg.teams[1].players[2].goalkeeper ? "o" : "");
  emit pgk204(msg.teams[1].players[3].goalkeeper ? "o" : "");
  emit pgk205(msg.teams[1].players[4].goalkeeper ? "o" : "");
  emit pgk206(msg.teams[1].players[5].goalkeeper ? "o" : "");

  emit pr101(QString::fromStdString(std::to_string(msg.teams[0].players[0].red_card_count)));
  emit pr102(QString::fromStdString(std::to_string(msg.teams[0].players[1].red_card_count)));
  emit pr103(QString::fromStdString(std::to_string(msg.teams[0].players[2].red_card_count)));
  emit pr104(QString::fromStdString(std::to_string(msg.teams[0].players[3].red_card_count)));
  emit pr105(QString::fromStdString(std::to_string(msg.teams[0].players[4].red_card_count)));
  emit pr106(QString::fromStdString(std::to_string(msg.teams[0].players[5].red_card_count)));
  emit pr201(QString::fromStdString(std::to_string(msg.teams[1].players[0].red_card_count)));
  emit pr202(QString::fromStdString(std::to_string(msg.teams[1].players[1].red_card_count)));
  emit pr203(QString::fromStdString(std::to_string(msg.teams[1].players[2].red_card_count)));
  emit pr204(QString::fromStdString(std::to_string(msg.teams[1].players[3].red_card_count)));
  emit pr205(QString::fromStdString(std::to_string(msg.teams[1].players[4].red_card_count)));
  emit pr206(QString::fromStdString(std::to_string(msg.teams[1].players[5].red_card_count)));

  emit py101(QString::fromStdString(std::to_string(msg.teams[0].players[0].yellow_card_count)));
  emit py102(QString::fromStdString(std::to_string(msg.teams[0].players[1].yellow_card_count)));
  emit py103(QString::fromStdString(std::to_string(msg.teams[0].players[2].yellow_card_count)));
  emit py104(QString::fromStdString(std::to_string(msg.teams[0].players[3].yellow_card_count)));
  emit py105(QString::fromStdString(std::to_string(msg.teams[0].players[4].yellow_card_count)));
  emit py106(QString::fromStdString(std::to_string(msg.teams[0].players[5].yellow_card_count)));
  emit py201(QString::fromStdString(std::to_string(msg.teams[1].players[0].yellow_card_count)));
  emit py202(QString::fromStdString(std::to_string(msg.teams[1].players[1].yellow_card_count)));
  emit py203(QString::fromStdString(std::to_string(msg.teams[1].players[2].yellow_card_count)));
  emit py204(QString::fromStdString(std::to_string(msg.teams[1].players[3].yellow_card_count)));
  emit py205(QString::fromStdString(std::to_string(msg.teams[1].players[4].yellow_card_count)));
  emit py206(QString::fromStdString(std::to_string(msg.teams[1].players[5].yellow_card_count)));

  emit pb101(QString::fromStdString(std::to_string(msg.teams[0].players[0].warning_count)));
  emit pb102(QString::fromStdString(std::to_string(msg.teams[0].players[1].warning_count)));
  emit pb103(QString::fromStdString(std::to_string(msg.teams[0].players[2].warning_count)));
  emit pb104(QString::fromStdString(std::to_string(msg.teams[0].players[3].warning_count)));
  emit pb105(QString::fromStdString(std::to_string(msg.teams[0].players[4].warning_count)));
  emit pb106(QString::fromStdString(std::to_string(msg.teams[0].players[5].warning_count)));
  emit pb201(QString::fromStdString(std::to_string(msg.teams[1].players[0].warning_count)));
  emit pb202(QString::fromStdString(std::to_string(msg.teams[1].players[1].warning_count)));
  emit pb203(QString::fromStdString(std::to_string(msg.teams[1].players[2].warning_count)));
  emit pb204(QString::fromStdString(std::to_string(msg.teams[1].players[3].warning_count)));
  emit pb205(QString::fromStdString(std::to_string(msg.teams[1].players[4].warning_count)));
  emit pb206(QString::fromStdString(std::to_string(msg.teams[1].players[5].warning_count)));
}

QString GameControlDataPanel::penalties(uint8_t penalty)
{
  return penalty == 0 ? "None" :
         penalty == 14 ? "Substitute" :
         penalty == 15 ? "Manual" :
         penalty == 30 ? "Ball manipulation" :
         penalty == 31 ? "Pushing" :
         penalty == 34 ? "Pickup/Incapable" :
         penalty == 35 ? "Service" :
         "Unknown";
}

QString GameControlDataPanel::time(int16_t sec)
{
  return QString::fromStdString(
    std::string(
      std::max(0, 2 - (int)(std::to_string(sec / 60)).size()), '0') +
    std::to_string(sec / 60) +
    ":" +
    std::string(
      std::max(0, 2 - (int)(std::to_string(sec % 60)).size()), '0') +
    std::to_string(sec % 60));
}

}  // namespace communication_rviz_plugin

PLUGINLIB_EXPORT_CLASS(
  communication_rviz_plugin::GameControlDataPanel,
  rviz_common::Panel)
