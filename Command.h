// Command.h
#ifndef COMMAND_H
#define COMMAND_H

/**
 * @class Command
 * @brief Abstract base class for commands.
 *
 * The Command class defines an interface for executing commands.
 * Concrete command classes should implement the execute method.
 */
class Command {
public:
    /**
     * @brief Executes the command.
     *
     * This method must be implemented by derived classes to define the command's behavior.
     */
    virtual void execute() = 0;

    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~Command() = default;
};

#endif // COMMAND_H
