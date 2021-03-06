#ifndef START_QPROCESS_REPEAT_H
#define START_QPROCESS_REPEAT_H

#include <QObject>
#include <QProcess>
#include <QStringList>

/**
 * @brief Start the process repeatly by QProcess
 */
class start_qprocess_repeat : public QObject
{
    Q_OBJECT

public:
    start_qprocess_repeat(QProcess &process,
                          const QString &program,
                          const QStringList &arguments);
    ~start_qprocess_repeat();

    start_qprocess_repeat(start_qprocess_repeat const&) = delete;
    start_qprocess_repeat& operator=(start_qprocess_repeat const&) = delete;

    start_qprocess_repeat(start_qprocess_repeat &&) noexcept;
    start_qprocess_repeat& operator=(start_qprocess_repeat &&) noexcept;

    void set_restart_limit(size_t restart_limit) noexcept;

private slots:
    void restart(QProcess::ProcessError error) noexcept;

private:
    QStringList arguments_;

    QProcess *process_;
    QString program_;

    size_t restart_limit_;
    size_t restart_time_;
};

#endif // START_QPROCESS_REPEAT_H
