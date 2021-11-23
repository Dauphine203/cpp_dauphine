#ifndef INTERPOLATION_IMPL_HPP
#define INTERPOLATION_IMPL_HPP

#include <vector>

namespace dauphine
{
	class interpolation_impl
	{
	public:
	
		virtual ~interplation_impl() = default;
		
		interpolation_impl&
		operator=(const interpolation_impl&) = delete;
		
		interpolation_impl(interpolation_impl&&) = delete;
		interpolation_impl&
		operator=(interpolation_impl&) = delete;
		
		double interpolate(double x) const;
		
		virtual interpolation_impl* clone() const = 0;
		
	protected:
	
		interpolation_impl(const std::vector<double>& x,
						   const std::vector<double>& y);
		interpolation_impl(const interpolation_impl&) = default;
		
		const std::vector<double>& get_x() const;
		const std::vector<double>& get_y() const;
		
	private:
	
		size_t find_upper_bound(double x) const;
		virtual double interpolate_impl(double x,
										size_t upper_bound) const = 0;
		
		std::vector<double> m_x;
		std::vector<double> m_y;
	};
	
	class spline_interpolation : public interpolation_impl
	{
	public:
	
		spline_interpolation(const std::vector<double>& x,
							 const std::vector<double>& y);
	
		interpolation_impl* clone() const override;
	private:
	
		spline_interpolation(const spline_interpolation&) = default;
		double interpolate_impl(double x,
								size_t upper_bound) const override;
		
		std::vector<double> m_y2;
	};
	
	class linear_interpolation : public interpolation_impl
	{
	public:
	
		linear_interpolation(const std::vector<double>& x,
							 const std::vector<double>& y);
		
		interpolation_impl* clone() const override;
		
	private:
	
		linear_interpolation(const linear_interpolation&) = default;
		double interpolate_impl(double x,
								size_t upper_bound) const override;
	};
	
}








#endif

