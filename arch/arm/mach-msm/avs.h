/*
 * Copyright (c) 2009,2012, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef AVS_H
#define AVS_H

#ifdef CONFIG_MSM_AVS_HW
u32 avs_get_avscsr(void);
void avs_set_avscsr(u32 avscsr);
u32 avs_get_avsdscr(void);
void avs_set_avsdscr(u32 avsdscr);
void avs_disable(int cpu);
void avs_enable(int cpu, u32 avsdscr);
#else
static inline u32 avs_get_avscsr(void)
{ return 0; }
static inline void avs_set_avscsr(u32 avscsr) {}
static inline u32 avs_get_avsdscr(void)
{ return 0; }
static inline void avs_set_avsdscr(u32 avsdscr) {}
static inline void avs_disable(int cpu) {}
static inline void avs_enable(int cpu, u32 avsdscr) {}
#endif

<<<<<<< HEAD
#define AVS_DISABLE(cpu) avs_disable(cpu)
#define AVS_ENABLE(cpu, x) avs_enable(cpu, x)
=======
#define AVS_DISABLE(cpu) do {			\
		if (get_cpu() == (cpu))		\
			avs_disable();		\
		put_cpu();			\
	} while (0);
>>>>>>> 994733e... msm: avs: Remove vestigial software based AVS

#endif
