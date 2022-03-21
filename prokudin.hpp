#ifndef SIDIS_SF_SET_PROKUDIN_HPP
#define SIDIS_SF_SET_PROKUDIN_HPP

namespace sidis {

using Real = double;

enum class Hadron {
	PI_P,
	PI_M,
};

/**
 * Use data files from \cite bastami2019ww to calculate structure functions.
 */
class ProkudinSfSet final {
	struct Impl;
	Impl* _impl;

	// Fragmentation functions.
	Real D1(Hadron h, unsigned fl, Real z, Real Q_sq) const;
	Real H1perpM1(Hadron h, unsigned fl, Real z, Real Q_sq) const;

	// Transverse momentum distributions.
	Real xf1(unsigned fl, Real x, Real Q_sq) const;
	Real xf1TperpM1(unsigned fl, Real x, Real Q_sq) const;
	Real xg1(unsigned fl, Real x, Real Q_sq) const;
	Real xgT(unsigned fl, Real x, Real Q_sq) const;
	Real xh1(unsigned fl, Real x, Real Q_sq) const;
	Real xh1M1(unsigned fl, Real x, Real Q_sq) const;
	Real xh1LperpM1(unsigned fl, Real x, Real Q_sq) const;
	Real xh1TperpM2(unsigned fl, Real x, Real Q_sq) const;
	Real xh1perpM1(unsigned fl, Real x, Real Q_sq) const;

public:
	ProkudinSfSet();
	ProkudinSfSet(ProkudinSfSet const& other) = delete;
	ProkudinSfSet(ProkudinSfSet&& other) noexcept;
	ProkudinSfSet& operator=(ProkudinSfSet const& other) = delete;
	ProkudinSfSet& operator=(ProkudinSfSet&& other) noexcept;
	virtual ~ProkudinSfSet();

	// Structure functions.
	Real F_UUT(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;
	Real F_UU_cos_phih(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;
	Real F_UU_cos_2phih(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;

	Real F_UL_sin_phih(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;
	Real F_UL_sin_2phih(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;

	Real F_UTT_sin_phih_m_phis(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;
	Real F_UT_sin_2phih_m_phis(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;
	Real F_UT_sin_3phih_m_phis(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;
	Real F_UT_sin_phis(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;
	Real F_UT_sin_phih_p_phis(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;

	Real F_LL(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;
	Real F_LL_cos_phih(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;

	Real F_LT_cos_phih_m_phis(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;
	Real F_LT_cos_2phih_m_phis(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;
	Real F_LT_cos_phis(Hadron h, Real x, Real z, Real Q_sq, Real ph_t_sq) const;
};

}

#endif

