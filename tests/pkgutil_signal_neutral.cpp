#include <libpkgcore/pkgutil.h>

#include <csignal>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

namespace {

volatile sig_atomic_t observed_signal = 0;

void record_signal(int signal)
{
  observed_signal = signal;
}

bool same_mask(const sigset_t& lhs, const sigset_t& rhs)
{
  for (int signal = 1; signal < NSIG; ++signal)
  {
    if (sigismember(&lhs, signal) != sigismember(&rhs, signal))
      return false;
  }

  return true;
}

} // namespace

int main()
{
  const int signals[] = { SIGHUP, SIGINT, SIGQUIT, SIGTERM };
  struct sigaction previous[4];
  struct sigaction action;

  action.sa_handler = record_signal;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;

  for (std::size_t i = 0; i < 4; ++i)
  {
    if (sigaction(signals[i], &action, &previous[i]) == -1)
    {
      std::cerr << "could not install test signal handler" << std::endl;
      return EXIT_FAILURE;
    }
  }

  sigset_t mask_before;
  sigset_t mask_after;
  if (sigprocmask(SIG_SETMASK, 0, &mask_before) == -1)
  {
    std::cerr << "could not read signal mask" << std::endl;
    return EXIT_FAILURE;
  }

  pkgutil util("signal-neutral-test");

  if (sigprocmask(SIG_SETMASK, 0, &mask_after) == -1)
  {
    std::cerr << "could not read signal mask" << std::endl;
    return EXIT_FAILURE;
  }

  if (!same_mask(mask_before, mask_after))
  {
    std::cerr << "pkgutil changed the signal mask" << std::endl;
    return EXIT_FAILURE;
  }

  for (std::size_t i = 0; i < 4; ++i)
  {
    struct sigaction current;
    if (sigaction(signals[i], 0, &current) == -1)
    {
      std::cerr << "could not read signal disposition" << std::endl;
      return EXIT_FAILURE;
    }

    if (current.sa_handler != record_signal)
    {
      std::cerr << "pkgutil changed signal disposition" << std::endl;
      return EXIT_FAILURE;
    }
  }

  for (std::size_t i = 0; i < 4; ++i)
    sigaction(signals[i], &previous[i], 0);

  return observed_signal == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
