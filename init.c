#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <net/mac80211.h>

#include "stats.h"
#include "relay.h"

struct kernel_symbol *mac80211_rx;

static int opp_mptcp_init(void)
{
    printk(KERN_INFO "opp_mptcp: hello!\n");

    init_stats();
    
    mac80211_rx = find_symbol("ieee80211_rx", NULL, NULL, true, false);
    if (mac80211_rx == NULL) {
        printk(KERN_INFO "Recompile your kernel with mac80211 support\n");
        return -EFAULT;
    }
    //mac80211_rx->value = (unsigned long)opp_mptcp_rx;
    printk(KERN_INFO "opp_mptcp: mac80211_rx = 0x%p\n", (void *)mac80211_rx->value);
    printk(KERN_INFO "opp_mptcp: opp_mptcp_rx = 0x%p\n", (void *)(unsigned long)opp_mptcp_rx);
    printk(KERN_INFO "opp_mptcp: ieee80211_rx = 0x%p\n", (void *)(unsigned long)ieee80211_rx);

    return 0;
}

//void cleanup_module(void)
static void opp_mptcp_exit(void)
{
    //mac80211_rx->value = (unsigned long)ieee80211_rx;
    remove_stats();
    printk(KERN_INFO "opp_mptcp: bye!\n");
}

module_init(opp_mptcp_init);
module_exit(opp_mptcp_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mike Hsueh-Hung Cheng xuehung@gmail.com");
