#ifndef __OPP_MPTCP_STATS
#define __OPP_MPTCP_STATS

#define STATS_FILENAME "opp_mptcp_stats"

int init_stats(void);
void remove_stats(void);

struct opp_mptcp_stats {
    unsigned long total;
    unsigned long data;
    unsigned long relayed;
};

#endif
