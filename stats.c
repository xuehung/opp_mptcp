#include <linux/proc_fs.h>
#include "stats.h"

struct proc_dir_entry *stats_file;

struct opp_mptcp_stats *stats;

int stats_read(char *page, char **start, off_t off, int count, int *eof, void *data)
{
    int ret;
    if(off > 0) ret = 0;
    else {
        ret = sprintf(page, "total frames received: %ld\n"
                "data frames received: %ld\n"
                "frames relayed: %ld\n",
                stats->total,
                stats->data,
                stats->relayed);
    }

    return ret;
}

int init_stats(void)
{
    stats_file = create_proc_entry(STATS_FILENAME, 0644, NULL);
    if(!stats_file) {
        printk(KERN_ALERT "opp_mptcp: ERROR! Could not initialize /proc/%s\n", STATS_FILENAME);
        remove_stats();
        return -ENOMEM;
    }
    stats_file->read_proc = stats_read;
    stats_file->mode    = S_IFREG | S_IRUGO;
    stats_file->uid     = 0;
    stats_file->gid     = 0;
    stats_file->size    = 0;

    stats = kmalloc(sizeof(struct opp_mptcp_stats), GFP_KERNEL);
    stats->total = 0;
    stats->data = 0;
    stats->relayed = 0;

    printk(KERN_INFO "/proc/%s created\n", STATS_FILENAME);
    return 0;
}

void remove_stats(void)
{
    remove_proc_entry(STATS_FILENAME, NULL);
    kfree(stats);
}
